// /u/beyond/hangzhou/santanyingyue.c ��̶ӳ��
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIW"��̶ӳ��"NOR);
        set("long", @LONG
��˵��̶ӳ��������Բ֮ҹ��������������ͬʱ͸�����Բ����������
����ÿ������֮ҹ�����õƹ⣬�������ϱ�ֽ���ƹ�͸��Բ�׵�ӳˮ�棬��
��һ������������ʱ�¹⡢�ƹ⡢���⽻ӳ���ԡ���Ӱ����Ӱ����Ӱ�ݳ�һ
Ƭ����ͬ��ӳ��һƬ��ɫ��ͼ������ʱ���ۺ��ϣ�����һ����Ȥ��
LONG
        );
        set("exits", ([
        "north" : __DIR__"juquqiao",
        "west" : __DIR__"huxinting",
]));
        setup();
}
