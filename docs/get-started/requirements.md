# System requirements

## Software

### Windows requirements

Up-to-date versions of Windows 7 and 10 work with SpatialOS.

| Required for | |
| --- | --- |
| All SpatialOS development | `spatial` CLI ([download directly](../get-started/setup/win.md#2-set-up-the-spatialos-cli)) <br> PowerShell 3.0 and later / Windows Command Prompt / Git BASH (For local deployments, you must use PowerShell or Command Prompt.) <br> [Visual C++ Redistributable for Visual Studio 2015](https://www.microsoft.com/en-gb/download/details.aspx?id=48145) |
| Unreal SDK | To use the Unreal SDK, you **must** build the Unreal engine from source. See the setup guides for instructions. <br> Unreal versions **4.16.3-release** and **4.17.1-release** have been tested with SpatialOS. Other versions may work fine, but have not been extensively tested. <br> [Visual Studio 2015](https://www.visualstudio.com/vs/older-downloads/) <br> [Windows SDK 8.1](https://developer.microsoft.com/en-us/windows/downloads/windows-8-1-sdk) (this is a requirement for Unreal itself) |

You can find installation instructions for the basic requirements in the [setup guide for Windows](../get-started/setup/win.md).


### Browsers

To access the Console and Inspector, you'll need one of the following:

* [Chrome](https://www.google.com/chrome/browser/desktop/) (latest stable version)
* [Firefox](https://www.mozilla.org/en-GB/firefox/new/) (latest stable version)

>`spatial worker build` and `spatial worker codegen` include an authentication step that opens a browser tab.
This authentication won't work if your default browser is Microsoft Edge or Internet Explorer.
It's most reliable when your default browser is Chrome or Firefox.

## Hardware

Hardware requirements apply to all operating systems.

> To use the Unreal SDK, you'll need a development machine that meets the
> required criteria for [Unreal Engine 4](https://wiki.unrealengine.com/Recommended_Hardware). We also recommend having around
> 100GB of space - the Unreal source alone takes up at least 50GB.

| | Recommended |
| --- | --- |
| Processor | i7 |
| Memory | 16GB RAM |
| Network | High-speed broadband internet connection |
| Storage | 12GB available space |

## Network settings

* Your firewall settings must allow **outbound TCP connections on ports 443 and 444** in order to authenticate on the
SpatialOS platform, download SDKs and contact other cloud services.

* You **must not filter inbound and outbound connections** to `localhost` (IP: `127.0.0.1`) or submit such connections to
proxy rules.

    You must also **not block the opening of ports** bound to `localhost`. This is required to run local
    deployments via the `spatial local` command.

* You must **allow TCP and UDP outbound connections on the 8000-8999 port range** for connecting clients to a
[cloud deployment](https://docs.improbable.io/reference/12.2/shared/glossary#cloud-deployment). This is also a requirement for any third-party users who want to connect to your deployments (when you share a game).
* You must keep port `22000` free for [local deployments](https://docs.improbable.io/reference/12.2/shared/glossary#local-deployment).

## Deployment environments

When you build workers to be deployed, the only deployment platform for *managed* workers is Linux.

Windows, macOS and Linux (experimental) also work for running external workers (like clients).
