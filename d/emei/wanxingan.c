// Room: /d/emei/wanxingan.c ������ ������

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "������" NOR);
	set("long", @LONG
̫��ƺ�������ǹ�����ʦ�����ġ�������ɽ����ɯ须��������źϳ�һ�䣬
Ҷ�Ӱ��ڻ��⣬��������������׶�ʢ��֮�����������Ժ�֮�߹�Ʒ�ʡ��ɴ�
�����ϱ����𶥣����������
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"jieyindian",
		"southup" : __DIR__"jinding",
	]));
        set("objects",([
		CLASS_D("emei") + "/jing-jia" : 1,
          ]));
	setup();

}
