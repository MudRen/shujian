// By River@SJ

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL"ɽ����"NOR);
	set("long", @LONG
�����Ѿ��ӽ����ɽ��ɽ���ˡ����ɽɽʷ�Ļ��ƾã�Ϊ�й����̷����
֮һ���ഫ��ԯ�Ƶ۵����ʵ��ڹ���ӡ��غ�ʱɽ��������۽�����������
���ݣ��չ���ɲ�鲼��塣
LONG );
	set("exits", ([
		"northwest"  : __DIR__"dukou2",
		"southup" : __DIR__"kongdong",
	]));

	set("outdoors", "����");
	setup();
}
