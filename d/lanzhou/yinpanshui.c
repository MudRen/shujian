//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "Ӫ��ˮ");
	set("long", @LONG
�����ǵ��������޳���ʱפ���ĵط��������ξ��з������������Դ�����
פ�����˺ü�����ˮ����ʹʿ���ǲ��ú��ֿ���ɬ����ˮ�������˵صİ�����
������ΪӪ��ˮ��������ľ�Ϊ�����񾮡���
LONG );

	set("resource/water", 1);
	set("drink_msg", "$N�����������һЩ��ˮ������������ȥ��\n");
	set("exits", ([
		"southwest" : __DIR__"bingcao",
                "east" : __DIR__"gccheng",
	]));

	set("outdoors", "����");
	setup();
}
