// Room: /d/city/duchang3.c
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "�����ĵ�");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
        );
        set("exits", ([
                "east"          : __DIR__"duchang", 
	 ]) );
       

 
        setup();
}

//�Ǿ���
int is_mirror() { return 1; }