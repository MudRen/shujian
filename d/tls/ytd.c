#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"Բͨ��"NOR);
        set("long",@LONG
��ǰ������Ϊ��ΰ�����﹩�������޴�ȴ󱯹����й���
������������е�ǧ�ֹ�������Ȼ����һ��󺺰��񾫵���ɣ���Ƕ
���ֱ�ʯ������������֮�������亱���������е�����һ������Ϊ��
���屦֮һ�������㰸�Ϸ�����͹��ĸ�����Ʒ��
LONG);       
        set("exits", ([
             "north" : __DIR__"xmd",
             "west" : __DIR__"yz6",
	]));

        set("coor/x",-340);
  set("coor/y",-300);
   set("coor/z",20);
   setup();
}