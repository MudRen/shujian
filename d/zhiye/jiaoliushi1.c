// ������
// jiaoliushi1.c
// augx@sj 9/24/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","������");
	set("long",
"�����Ǽ������ƹ�ĳ����ң��������ƹ���������ղء��˴�����������
�������ߣ��Լ������ҩ�ݡ��˴�Ҳ��Ϊ�����ǽ������飬�Ƽ���Ʒ�ĳ�����
"); 
        
	set("exits",([
		"east"  : __DIR__"jimaidian1",
	]));
	
	set("indoors", "���ݳ�");
	set("incity",1);
	setup();
	
	call_other( "/clone/board/worker1_b", "???" );
}
