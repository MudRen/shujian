// Room: /d/emei/woyunan.c ������ ������

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "������" NOR);
	set("long", @LONG
�������Ա��и�����Ȫ����˵��ǰ������ˮ�˶���ɺԣ�����Ϊ֮�о���
����Ȫˮ���������������ֱ��Ƕù�̨���Ա��ǻ����֡�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"jinding",
		"southup" : __DIR__"duguangtai",
	]));
        set("objects",([
		CLASS_D("emei") + "/jing-xuan" : 1,
          ]));
	setup();
}
