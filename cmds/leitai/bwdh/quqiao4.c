//quqiao.c ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
	set("short",HIY"����"NOR);
	set("long", @LONG
һ��С�ɾ��Ƶ����ź���ڳ����ϣ�������������һ��Ϊ�����������ˮ
�����峺�����渡��Щʢ����˯����͸��˯���ķ�϶��Լ�ɼ���β��ɫ������
ˮ�����еػ����ζ���Զ����ǽ���µ�һ�԰Ž������Ļ��俪�������֣���
�������ĳ�����������������
LONG
        );

	set("exits", ([
		"south" : __DIR__"jiashan",
		"southwest" :__DIR__"quqiao1",
		"southeast" :__DIR__"quqiao3",
		"northwest" :__DIR__"caodi3",
		"northeast" :__DIR__"caodi4",
		"north" : __DIR__"zhongting",
	]));
	set("outdoors", "�Խ�ɽׯ");
	setup();
}

#include "sjsz_room.h";
