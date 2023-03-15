#include <iostream>
#include <sstream>
#include <unordered_map>
#include <windows.h>

#include "RegisteryReader.h"
#include "KMSClient.h"
#include "Log.h"

std::wstring get_gvlk_from_edition(const std::wstring& edition_id) noexcept {
    std::unordered_map<std::wstring, std::wstring> lookup = {
        {L"Enterprise", L"NPPR9-FWDCX-D2C8J-H872K-2YT43"},
        {L"EnterpriseN", L"DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4"},

        {L"EnterpriseS", L"M7XTQ-FN8P6-TTKYV-9D4CC-J462D"},
        {L"EnterpriseSN", L"92NFX-8DJQP-P6BBQ-THF9C-7CG2H"},

        {L"EnterpriseG", L"YYVX9-NTFWV-6MDM3-9PT4T-4M68B"},
        {L"EnterpriseGN", L"44RPN-FTY23-9VTTB-MP9BX-T84FV"},

        {L"Professional", L"W269N-WFGWX-YVC9B-4J6C9-T83GX"},
        {L"ProfessionalN", L"MH37W-N47XK-V7XM9-C7227-GCQG9"},

        {L"Core", L"TX9XD-98N7V-6WMQ6-BX7FG-H8Q99"},
        {L"CoreN", L"3KHY7-WNT83-DGQKR-F7HPR-844BM"},
        {L"CoreCountrySpecific", L"PVMJN-6DFY6-9CCP6-7BKTT-D3WVR"},
        {L"CoreSingleLanguage", L"7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH"},
        
        {L"Education", L"NW6C2-QMPVW-D7KKK-3GKT6-VCFB2"},
        {L"EducationN", L"2WH4N-8QGBV-H22JP-CT43Q-MDWWJ"},

        {L"ProfessionalWorkstation", L"NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J"},
        {L"ProfessionalWorkstationN", L"9FNHH-K3HBT-3W4TD-6383H-6XYWF"},

        {L"ProfessionalEducation", L"6TP4R-GNPTD-KYYHQ-7B7DP-J447Y"},
        {L"ProfessionalEducationN", L"YVWGF-BXNMC-HTQYQ-CPQ99-66QFC"},
    };

    return lookup[edition_id];
}

std::wstring get_edition_id() {
    const LPCWSTR location = L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";
    const LPCWSTR key = L"EditionID";

    return RegistryReader(key, location).read_wstr();
}

constexpr LPCWSTR KMS_SERVER = L"";
constexpr const short KMS_PORT = 1688;

int main()
{
    try {
        std::wstring edition_id = get_edition_id();
        LOG(INFO) << L"Attempting to activate -> " << edition_id << std::endl;

        LOG(INFO) << "Setting KMS server -> " << KMS_SERVER << ":" << KMS_PORT << std::endl;
        KMSClient::set_kms_server(KMS_SERVER, KMS_PORT);

        std::wstring product_key = get_gvlk_from_edition(edition_id);
        LOG(INFO) << L"Registering product key -> " << product_key << std::endl;
        KMSClient::set_gvlk_key(product_key);

        LOG(INFO) << L"Requesting activation.." << std::endl;
        KMSClient::request_activation();

        LOG(INFO) << "Success :: Product activation successful" << std::endl;
    }
    catch (const std::exception&) {
        LOG(FATAL) << "Product activation unsuccessful, see below" << std::endl;
        try {
            std::rethrow_exception(std::current_exception());
        }
        catch (const RegistryError& e) {
            LOG(RAW) << "\t ERROR (reg@" << e.error_code() << ") " << e.what() << std::endl;
        }
        catch (const KMSError& e) {
            LOG(RAW) << "\t ERROR (kms@" << e.error_code() << ") " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            LOG(RAW) << "\t ERROR (internal@???) " << e.what() << std::endl;
        }
    }

    Sleep(2000);
}