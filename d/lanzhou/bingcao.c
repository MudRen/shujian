//By River@Sj

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ӫ��ˮ�����ϣ�ƽʱ�˼���������Ϊ����ɳĮ�ﳤ��һ�������
ҩ��----�����ݡ�����������˵����ҩ���ܽ�ٶ�������ż�����������ֲݣ�
����ɳĮ�ﳣ�ж����û����ΪΣ�ա�
LONG );
	set("exits", ([
		"southwest" : "/d/group/entry/lzshixia",
		"northeast" : __DIR__"yinpanshui",
	]));
	set("objects", ([
		__DIR__"npc/wugong" : 1,
	]));

	set("outdoors", "����");
	setup();
}
