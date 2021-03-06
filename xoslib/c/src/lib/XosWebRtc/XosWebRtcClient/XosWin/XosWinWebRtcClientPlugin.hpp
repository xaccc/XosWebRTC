///////////////////////////////////////////////////////////////////////
/// Copyright 2012, Google Inc.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 
///  1. Redistributions of source code must retain the above copyright notice,
///     this list of conditions and the following disclaimer.
///  2. Redistributions in binary form must reproduce the above copyright notice,
///     this list of conditions and the following disclaimer in the documentation
///     and/or other materials provided with the distribution.
///  3. The name of the author may not be used to endorse or promote products
///     derived from this software without specific prior written permission.
/// 
/// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
/// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
/// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
/// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
/// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
/// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
/// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
/// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
/// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
/// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
///   File: XosWinWebRtcClientPlugin.hpp
///
/// Author: $author$
///   Date: 12/10/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINWEBRTCCLIENTPLUGIN_HPP
#define _XOSWINWEBRTCCLIENTPLUGIN_HPP

#include "XosWinWebRtcClientPluginWindow.hpp"
#include "XosWinWebRtcClientPluginWindowPeer.hpp"
#include "XosWinWebRtcClientPluginInterface.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWebRtcClientPluginInterface
///
///  Author: $author$
///    Date: 12/10/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWebRtcClientPluginInterface
XosWinWebRtcClientPluginImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWebRtcClientPluginExtend
///
///  Author: $author$
///    Date: 12/10/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosWinWebRtcClientPluginExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinWebRtcClientPlugin
///
/// Author: $author$
///   Date: 12/10/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinWebRtcClientPlugin
: virtual public XosWinWebRtcClientPluginImplement,
  public XosWinWebRtcClientPluginExtend
{
public:
    typedef XosWinWebRtcClientPluginImplement Implements;
    typedef XosWinWebRtcClientPluginExtend Extends;

    XosWinWebRtcClientPluginWindow m_window;
    XosWinWebRtcClientPluginWindowPeer m_windowPeer;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinWebRtcClientPlugin
    ///
    ///       Author: $author$
    ///         Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinWebRtcClientPlugin
    (const char* serverName=XOSWEBRTCCLIENTBASEWINDOW_DEFAULT_SERVER_NAME, 
     int serverPort=XOSWEBRTCCLIENTBASEWINDOW_DEFAULT_SERVER_PORT,
     bool showConnectionState=XOSWEBRTCCLIENTBASEWINDOW_DEFAULT_SHOW_CONNECTION_STATE,
     bool handleButtonEvents=XOSWEBRTCCLIENTBASEWINDOW_DEFAULT_HANDLE_BUTTON_EVENTS)
    : m_window(*this, serverName, serverPort, showConnectionState, handleButtonEvents),
      m_windowPeer(m_window)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinWebRtcClientPlugin
    ///
    ///      Author: $author$
    ///        Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinWebRtcClientPlugin()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // connection to server
    ///////////////////////////////////////////////////////////////////////
    virtual bool ConnectToServer(const std::string& serverName, int serverPort) {
        return m_window.ConnectToServer(serverName, serverPort); 
    }
    virtual void SetServerName(const std::string& serverName) {
        m_window.SetServerName(serverName); 
    }
    virtual void SetServerPort(int serverPort) {
        m_window.SetServerPort(serverPort); 
    }
    virtual bool ConnectToServer() {
        return m_window.ConnectToServer(); 
    }
    virtual bool DisconnectFromServer() { 
        return m_window.DisconnectFromServer(); 
    }

    ///////////////////////////////////////////////////////////////////////
    // connection to peer
    ///////////////////////////////////////////////////////////////////////
    virtual bool ConnectToPeer(const std::string& peerName) {
        return m_window.ConnectToPeer(peerName); 
    }
    virtual bool ConnectToPeer(int peerId) {
        return m_window.ConnectToPeer(peerId); 
    }
    virtual bool ConnectToPeer() {
        return m_window.ConnectToPeer(); 
    }
    virtual bool DisconnectFromPeer() { 
        return m_window.DisconnectFromPeer(); 
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnWindowAttached
    ///
    ///    Author: $author$
    ///      Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnWindowAttached(HWND hWnd)
    {
        m_window.OnWindowAttached(hWnd);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnWindowDetached
    ///
    ///    Author: $author$
    ///      Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnWindowDetached(HWND hWnd)
    {
        m_window.OnWindowDetached(hWnd);
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnWindowMessage
    ///
    ///   Author: $author$
    ///     Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT OnWindowMessage
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = m_window.OnWindowMessage(hWnd, msg, wParam, lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINWEBRTCCLIENTPLUGIN_HPP 
        

