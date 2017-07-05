#include "qgis_devmaptoolidentifyaction.h"
#include "qgis_dev.h"

#include <QMessageBox>
#include <QList>

qgis_devMapToolIdentifyAction::qgis_devMapToolIdentifyAction( QgsMapCanvas * canvas )
    : QgsMapToolIdentify( canvas )
{

}

qgis_devMapToolIdentifyAction::~qgis_devMapToolIdentifyAction()
{

}

void qgis_devMapToolIdentifyAction::canvasReleaseEvent( QMouseEvent * e )
{
    IdentifyMode mode = QgsMapToolIdentify::LayerSelection; // ����ʶ��ģʽ
    QList<IdentifyResult> results = QgsMapToolIdentify::identify( e->x(), e->y(), mode ); // ��䷵��ʶ����

    if ( results.isEmpty() )
    {
        qgis_dev::instance()->statusBar()->showMessage( tr( "No features at this position found." ) );
    }
    else
    {
        // ��ʾ��ʶ�������������ʾ���������չʾ��ʽ�����Զ���
        IdentifyResult feature = results.at( 0 );
        QString title = feature.mLayer->name();
        QString content = feature.mFeature.attribute( 1 ).toString();
        // ��ʾʶ�𴰿�
        QMessageBox::critical( NULL,
                               title,
                               content );
    }
}

