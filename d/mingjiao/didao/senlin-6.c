// senlin-6.c ��ɼ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",MAG"��ɼ��"NOR);
       set("long", @LONG
���������̹������ϵ�һƬ��ɼ�֡���Χȫ�Ǽ�ʮ�ɸߵ���ɼ����ʵ��֦
Ҷ��һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ���һ�߽���������ɭ�֣�
ֱ����������øϿ��뿪��
LONG);    
	set("exits", ([
		"north" : __DIR__"senlin-"+(1+random(9)),
		"south" : __DIR__"senlin-"+(1+random(9)),
                "east" : __DIR__"senlin-"+(1+random(9)),
                "west" : "/d/mingjiao/jinqi",
	]));             	
        set("outdoors", "���̹�����");
        set("coor/x",-260);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-260);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}

void init()
{
       set("exits/east", __DIR__"senlin-"+(1+random(9)) );
       set("exits/south", __DIR__"senlin-"+(1+random(9)) );
       set("exits/north",  __DIR__"senlin-"+(1+random(9)));
}
