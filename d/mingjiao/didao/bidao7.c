// /d/mingjiao/bidao7.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
        set("short","�ص�");
        set("long", @LONG
���ߵ����ǰ��������߸���·��
LONG
     );
    	set("exits", ([
		"westup" : __DIR__"bidao6",				
		"Ҽ" :  __DIR__"mbidao1",
		"��" :  __DIR__"mbidao1",
		"��" :  __DIR__"mbidao1",
		"��" :  __DIR__"mbidao1",
		"��" :  __DIR__"bidao8",
		"½" :  __DIR__"mbidao1",
		"��" :  __DIR__"mbidao1",
	]));             
	 set("item_desc", ([
		"Ҽ" : "����һƬ�ڰ���ʲô�������塣\n",
		"��" : "����һƬ�ڰ���ʲô�������塣\n",
		"��" : "����һƬ�ڰ���ʲô�������塣\n",
		"��" : "����һƬ�ڰ���ʲô�������塣\n",
		"��" : "����һƬ�ڰ���ʲô�������塣\n",
		"½" : "����һƬ�ڰ���ʲô�������塣\n",
		"��" : "����һƬ�ڰ���ʲô�������塣\n",
	]));
        setup();
}
