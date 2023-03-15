#include <iostream>
#include <sstream>
#include <unordered_map>
#include <windows.h>

#include "RegisteryReader.h"
#include "KMSClient.h"
#include "Log.h"

std::wstring get_gvlk_from_edition(const std::wstring& edition_id) noexcept {
    std::unordered_map<std::wstring, std::wstring> lookup = {
        {L"Professional", L"W269N-WFGWX-YVC9B-4J6C9-T83GX"},
        {L"Enterprise", L"NPPR9-FWDCX-D2C8J-H872K-2YT43"},
        {L"EnterpriseS", L"M7XTQ-FN8P6-TTKYV-9D4CC-J462D"},
    };

    return lookup[edition_id];
        //Windows Server 2022
        //Operating system edition 	KMS Client Product Key
        //Windows Server 2022 Datacenter 	WX4NM - KYWYW - QJJR4 - XV3QB - 6VM33
        //Windows Server 2022 Datacenter
        //Azure Edition 	NTBV8 - 9K7Q8 - V27C6 - M2BTV - KHMXV
        //Windows Server 2022 Standard 	VDYBN - 27WPP - V4HQT - 9VMD4 - VMK7H
        //Windows Server 2019
        //Operating system edition 	KMS Client Product Key
        //Windows Server 2019 Datacenter 	WMDGN - G9PQG - XVVXX - R3X43 - 63DFG
        //Windows Server 2019 Standard 	N69G4 - B89J2 - 4G8F4 - WWYCC - J464C
        //Windows Server 2019 Essentials 	WVDHN - 86M7X - 466P6 - VHXV7 - YY726
        //Windows Server 2016
        //Operating system edition 	KMS Client Product Key
        //Windows Server 2016 Datacenter 	CB7KF - BWN84 - R7R2Y - 793K2 - 8XDDG
        //Windows Server 2016 Standard 	WC2BQ - 8NRM3 - FDDYY - 2BFGV - KHKQY
        //Windows Server 2016 Essentials 	JCKRF - N37P4 - C2D82 - 9YXRT - 4M63B
        //Windows Server(Semi - Annual Channel versions)
        //Windows Server, versions 20H2, 2004, 1909, 1903, and 1809
        //Operating system edition 	KMS Client Product Key
        //Windows Server Datacenter 	6NMRW - 2C8FM - D24W7 - TQWMY - CWH2D
        //Windows Server Standard 	N2KJX - J94YW - TQVFB - DG9YT - 724CC

        //Windows 11 and Windows 10 (Semi - Annual Channel versions)

        //See the Windows lifecycle fact sheet for information about supported versions and end of service dates.
        //Operating system edition 	KMS Client Product Key
        //Windows 11 Pro
        //Windows 10 Pro 	W269N - WFGWX - YVC9B - 4J6C9 - T83GX
        //Windows 11 Pro N
        //Windows 10 Pro N 	MH37W - N47XK - V7XM9 - C7227 - GCQG9
        //Windows 11 Pro for Workstations
        //Windows 10 Pro for Workstations 	NRG8B - VKK3Q - CXVCJ - 9G2XF - 6Q84J
        //Windows 11 Pro for Workstations N
        //Windows 10 Pro for Workstations N 	9FNHH - K3HBT - 3W4TD - 6383H - 6XYWF
        //Windows 11 Pro Education
        //Windows 10 Pro Education 	6TP4R - GNPTD - KYYHQ - 7B7DP - J447Y
        //Windows 11 Pro Education N
        //Windows 10 Pro Education N 	YVWGF - BXNMC - HTQYQ - CPQ99 - 66QFC
        //Windows 11 Education
        //Windows 10 Education 	NW6C2 - QMPVW - D7KKK - 3GKT6 - VCFB2
        //Windows 11 Education N
        //Windows 10 Education N 	2WH4N - 8QGBV - H22JP - CT43Q - MDWWJ
        //Windows 11 Enterprise
        //Windows 10 Enterprise 	NPPR9 - FWDCX - D2C8J - H872K - 2YT43
        //Windows 11 Enterprise N
        //Windows 10 Enterprise N 	DPH2V - TTNVB - 4X9Q3 - TJR4H - KHJW4
        //Windows 11 Enterprise G
        //Windows 10 Enterprise G 	YYVX9 - NTFWV - 6MDM3 - 9PT4T - 4M68B
        //Windows 11 Enterprise G N
        //Windows 10 Enterprise G N 	44RPN - FTY23 - 9VTTB - MP9BX - T84FV

        //Windows 10 (LTSC / LTSB versions)
        //Windows 10 LTSC 2021 and 2019
        //Operating system edition 	KMS Client Product Key
        //Windows 10 Enterprise LTSC 2021
        //Windows 10 Enterprise LTSC 2019 	M7XTQ - FN8P6 - TTKYV - 9D4CC - J462D
        //Windows 10 Enterprise N LTSC 2021
        //Windows 10 Enterprise N LTSC 2019 	92NFX - 8DJQP - P6BBQ - THF9C - 7CG2H
        //Windows 10 LTSB 2016
        //Operating system edition 	KMS Client Product Key
        //Windows 10 Enterprise LTSB 2016 	DCPHK - NFMTC - H88MJ - PFHPY - QJ4BJ
        //Windows 10 Enterprise N LTSB 2016 	QFFDN - GRT3P - VKWWX - X7T3R - 8B639
        //Windows 10 LTSB 2015
        //Operating system edition 	KMS Client Product Key
        //Windows 10 Enterprise 2015 LTSB 	WNMTR - 4C88C - JK8YV - HQ7T2 - 76DF9
        //Windows 10 Enterprise 2015 LTSB N 	2F77B - TNFGY - 69QQF - B8YKP - D69TJ
        //Earlier versions of Windows Server
        //Windows Server, version 1803
        //Operating system edition 	KMS Client Product Key
        //Windows Server Datacenter 	2HXDN - KRXHB - GPYC7 - YCKFJ - 7FVDG
        //Windows Server Standard 	PTXN8 - JFHJM - 4WC78 - MPCBR - 9W4KR
        //Windows Server, version 1709
        //Operating system edition 	KMS Client Product Key
        //Windows Server Datacenter 	6Y6KB - N82V8 - D8CQV - 23MJW - BWTG6
        //Windows Server Standard 	DPCNP - XQFKJ - BJF7R - FRC8D - GF6G4
        //Windows Server 2012 R2
        //Operating system edition 	KMS Client Product Key
        //Windows Server 2012 R2 Standard 	D2N9P - 3P6X9 - 2R39C - 7RTCD - MDVJX
        //Windows Server 2012 R2 Datacenter 	W3GGN - FT8W3 - Y4M27 - J84CP - Q3VJ9
        //Windows Server 2012 R2 Essentials 	KNC87 - 3J2TX - XB4WP - VCPJV - M4FWM
        //Windows Server 2012
        //Operating system edition 	KMS Client Product Key
        //Windows Server 2012 	BN3D2 - R7TKB - 3YPBD - 8DRP2 - 27GG4
        //Windows Server 2012 N 	8N2M2 - HWPGY - 7PGT9 - HGDD8 - GVGGY
        //Windows Server 2012 Single Language 	2WN2H - YGCQR - KFX6K - CD6TF - 84YXQ
        //Windows Server 2012 Country Specific 	4K36P - JN4VD - GDC6V - KDT89 - DYFKP
        //Windows Server 2012 Standard 	XC9B7 - NBPP2 - 83J2H - RHMBY - 92BT4
        //Windows Server 2012 MultiPoint Standard 	HM7DN - YVMH3 - 46JC3 - XYTG7 - CYQJJ
        //Windows Server 2012 MultiPoint Premium 	XNH6W - 2V9GX - RGJ4K - Y8X6F - QGJ2G
        //Windows Server 2012 Datacenter 	48HP8 - DN98B - MYWDG - T2DCC - 8W83P
        //Windows Server 2008 R2
        //Operating system edition 	KMS Client Product Key
        //Windows Server 2008 R2 Web 	6TPJF - RBVHG - WBW2R - 86QPH - 6RTM4
        //Windows Server 2008 R2 HPC edition 	TT8MH - CG224 - D3D7Q - 498W2 - 9QCTX
        //Windows Server 2008 R2 Standard 	YC6KT - GKW9T - YTKYR - T4X34 - R7VHC
        //Windows Server 2008 R2 Enterprise 	489J6 - VHDMP - X63PK - 3K798 - CPX3Y
        //Windows Server 2008 R2 Datacenter 	74YFP - 3QFB3 - KQT8W - PMXWJ - 7M648
        //Windows Server 2008 R2 for Itanium - based Systems 	GT63C - RJFQ3 - 4GMB6 - BRFB9 - CB83V
        //Windows Server 2008
        //Operating system edition 	KMS Client Product Key
        //Windows Web Server 2008 	WYR28 - R7TFJ - 3X2YQ - YCY4H - M249D
        //Windows Server 2008 Standard 	TM24T - X9RMF - VWXK6 - X8JC9 - BFGM2
        //Windows Server 2008 Standard without Hyper - V 	W7VD6 - 7JFBR - RX26B - YKQ3Y - 6FFFJ
        //Windows Server 2008 Enterprise 	YQGMW - MPWTJ - 34KDK - 48M3W - X4Q6V
        //Windows Server 2008 Enterprise without Hyper - V 	39BXF - X8Q23 - P2WWT - 38T2F - G3FPG
        //Windows Server 2008 HPC 	RCTX3 - KWVHP - BR6TB - RB6DM - 6X7HP
        //Windows Server 2008 Datacenter 	7M67G - PC374 - GR742 - YH8V4 - TCBY3
        //Windows Server 2008 Datacenter without Hyper - V 	22XQ2 - VRXRG - P8D42 - K34TD - G3QQC
        //Windows Server 2008 for Itanium - Based Systems 	4DWFP - JF3DJ - B7DTH - 78FJB - PDRHK
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