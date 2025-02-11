#include <NoweGlobal.h>
#include <QXmppVCardManager.h>

namespace Nowe {

class nowe_on_exit {
public:
    ~nowe_on_exit()
    {
        myClient()->disconnectFromServer();
    }
} static _;

QXmppClient* myClient() {
    static QXmppClient client;
    return &client;
}

const QXmppVCardIq& myVCard() {
    return myClient()->findExtension<QXmppVCardManager>()->clientVCard();
}

QString myJid() {
    return myClient()->configuration().jid();
}

QString myJidBare() {
    return myClient()->configuration().jidBare();
}

}
