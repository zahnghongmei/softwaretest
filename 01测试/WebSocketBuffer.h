#ifndef VUSER_WEBSOCKET_BUFFER_HEADER
#define VUSER_WEBSOCKET_BUFFER_HEADER

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive0[] = "<open xmlns='urn:ietf:params:xml:ns:xmpp-framing' version='1.0' xml:lang='en' id"
                        "='2180439051' from='easemob.com'/>";
long WebSocketReceiveLen0   = sizeof(WebSocketReceive0) - 1;	// (record-time: 114 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive1[] = "<stream:features xmlns:stream='http://etherx.jabber.org/streams'><mechanisms xml"
                        "ns='urn:ietf:params:xml:ns:xmpp-sasl'><mechanism>PLAIN</mechanism></mechanisms><"
                        "c xmlns='http://jabber.org/protocol/caps' hash='sha-1' node='http://www.easemob."
                        "com/' ver='8CVZGa77VxP1VxmLlVkQdoIUnKU='/><register xmlns='http://jabber.org/fea"
                        "tures/iq-register'/></stream:features>";
long WebSocketReceiveLen1   = sizeof(WebSocketReceive1) - 1;	// (record-time: 358 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive2[] = "<success xmlns='urn:ietf:params:xml:ns:xmpp-sasl'/>";
long WebSocketReceiveLen2   = sizeof(WebSocketReceive2) - 1;	// (record-time: 51 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive3[] = "<open xmlns='urn:ietf:params:xml:ns:xmpp-framing' version='1.0' xml:lang='en' id"
                        "='3297807179' from='easemob.com'/>";
long WebSocketReceiveLen3   = sizeof(WebSocketReceive3) - 1;	// (record-time: 114 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive4[] = "<stream:features xmlns:stream='http://etherx.jabber.org/streams'><bind xmlns='ur"
                        "n:ietf:params:xml:ns:xmpp-bind'/><session xmlns='urn:ietf:params:xml:ns:xmpp-ses"
                        "sion'/><ver xmlns='urn:xmpp:features:rosterver'/><c xmlns='http://jabber.org/pro"
                        "tocol/caps' hash='sha-1' node='http://www.easemob.com/' ver='8CVZGa77VxP1VxmLlVk"
                        "QdoIUnKU='/><register xmlns='http://jabber.org/features/iq-register'/></stream:f"
                        "eatures>";
long WebSocketReceiveLen4   = sizeof(WebSocketReceive4) - 1;	// (record-time: 408 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive5[] = "<iq xmlns='jabber:client' id='_bind_auth_2' type='result'><bind xmlns='urn:ietf:"
                        "params:xml:ns:xmpp-bind'><jid>1197180723253749#center-test_115201811061611139ftr"
                        "mgurx@easemob.com/webim_1554888504856</jid></bind></iq>";
long WebSocketReceiveLen5   = sizeof(WebSocketReceive5) - 1;	// (record-time: 215 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive6[] = "<iq type='result' xmlns='jabber:client' id='_session_auth_2'/>";
long WebSocketReceiveLen6   = sizeof(WebSocketReceive6) - 1;	// (record-time: 62 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive7[] = "<message xmlns='jabber:client' from='1197180723253749#center-test_admin@easemob."
                        "com' to='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com' ty"
                        "pe='chat' id='589314075037542392'><body>{&quot;bodies&quot;:[{&quot;msg&quot;:&q"
                        "uot;"
                        "\xe3\x80\x90\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8\xe3\x80\x91\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-09 10:00&quot;,&quot;type&quot;:&quot;txt&quot;}],&quot;ext&quot;:{&quo"
                        "t;msg&quot;:&quot;{\\&quot;msg\\&quot;:\\&quot;{\\\\\\&quot;action\\\\\\&quot;:\\"
                        "\\\\&quot;"
                        "\xe6\x9f\xa5\xe7\x9c\x8b\xe8\xaf\xa6\xe6\x83\x85"
                        "\\\\\\&quot;,\\\\\\&quot;appname\\\\\\&quot;:\\\\\\&quot;"
                        "\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8"
                        "\\\\\\&quot;,\\\\\\&quot;appurl\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX"
                        "-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\&quot;,\\\\\\&quot;content\\\\\\"
                        "&quot;:\\\\\\&quot;"
                        "\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-09 10:00\\\\\\&quot;,\\\\\\&quot;contentType\\\\\\&quot;:\\\\\\&quot;"
                        "\xe8\xb7\xb3\xe8\xbd\xac"
                        "\\\\\\&quot;,\\\\\\&quot;logo\\\\\\&quot;:\\\\\\&quot;https://oss.dacube.cn/mesg"
                        "-admin/0019f949-8567-4610-a9f0-7d536b853601/15.png\\\\\\&quot;,\\\\\\&quot;pcurl"
                        "\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redire"
                        "ct?type=all\\\\\\&quot;}\\&quot;,\\&quot;type\\&quot;:\\&quot;app\\&quot;}&quot;"
                        ",&quot;type&quot;:&quot;app&quot;},&quot;from&quot;:&quot;appadmin&quot;,&quot;t"
                        "o&quot;:&quot;115201811061611139ftrmgurx&quot;}</body><delay xmlns='urn:xmpp:del"
                        "ay' stamp='2019-04-09T01:59:35.416Z'/></message>";
long WebSocketReceiveLen7   = sizeof(WebSocketReceive7) - 1;	// (record-time: 1315 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive8[] = "<message xmlns='jabber:client' from='1197180723253749#center-test_admin@easemob."
                        "com' to='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com' ty"
                        "pe='chat' id='589685153928841256'><body>{&quot;bodies&quot;:[{&quot;msg&quot;:&q"
                        "uot;"
                        "\xe3\x80\x90\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8\xe3\x80\x91\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-10 10:00&quot;,&quot;type&quot;:&quot;txt&quot;}],&quot;ext&quot;:{&quo"
                        "t;msg&quot;:&quot;{\\&quot;msg\\&quot;:\\&quot;{\\\\\\&quot;action\\\\\\&quot;:\\"
                        "\\\\&quot;"
                        "\xe6\x9f\xa5\xe7\x9c\x8b\xe8\xaf\xa6\xe6\x83\x85"
                        "\\\\\\&quot;,\\\\\\&quot;appname\\\\\\&quot;:\\\\\\&quot;"
                        "\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8"
                        "\\\\\\&quot;,\\\\\\&quot;appurl\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX"
                        "-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\&quot;,\\\\\\&quot;content\\\\\\"
                        "&quot;:\\\\\\&quot;"
                        "\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-10 10:00\\\\\\&quot;,\\\\\\&quot;contentType\\\\\\&quot;:\\\\\\&quot;"
                        "\xe8\xb7\xb3\xe8\xbd\xac"
                        "\\\\\\&quot;,\\\\\\&quot;logo\\\\\\&quot;:\\\\\\&quot;https://oss.dacube.cn/mesg"
                        "-admin/0019f949-8567-4610-a9f0-7d536b853601/15.png\\\\\\&quot;,\\\\\\&quot;pcurl"
                        "\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redire"
                        "ct?type=all\\\\\\&quot;}\\&quot;,\\&quot;type\\&quot;:\\&quot;app\\&quot;}&quot;"
                        ",&quot;type&quot;:&quot;app&quot;},&quot;from&quot;:&quot;appadmin&quot;,&quot;t"
                        "o&quot;:&quot;115201811061611139ftrmgurx&quot;}</body><delay xmlns='urn:xmpp:del"
                        "ay' stamp='2019-04-10T01:59:33.965Z'/></message>";
long WebSocketReceiveLen8   = sizeof(WebSocketReceive8) - 1;	// (record-time: 1315 bytes)

#endif
