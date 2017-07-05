#include "qgis_dev_dockbrowsertreeview.h"

#include <QMenu>
#include <QFileDialog>
#include <QTreeView>

qgis_dev_dockBrowserTreeView::qgis_dev_dockBrowserTreeView( QWidget *parent )
    : QgsBrowserTreeView( parent )
{
    setDragDropMode( QTreeView::DragDrop );
    setSelectionMode( QAbstractItemView::ExtendedSelection );
    setContextMenuPolicy( Qt::CustomContextMenu );
    setHeaderHidden( true );
    setDropIndicatorShown( true );
}

qgis_dev_dockBrowserTreeView::~qgis_dev_dockBrowserTreeView()
{

}

void qgis_dev_dockBrowserTreeView::dragEnterEvent( QDragEnterEvent* e )
{
    // �����ļ��Ͻ���
    e->accept();
}

void qgis_dev_dockBrowserTreeView::dragMoveEvent( QDragMoveEvent* e )
{
    QTreeView::dragMoveEvent( e );
    if ( !e->mimeData()->hasFormat( "application/x-vnd.qgis.qgis.uri" ) )
    {
        e->ignore();
        return;
    }
}
