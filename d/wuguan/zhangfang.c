//test.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�ʷ�"NOR);
	set("long", @LONG
��������ݵ��ʷ����ı�ѩ�׵�ǽ���м��и����̨����̨ǰ�Ϸ�����һ
�����ӣ�paizi���� ���Ｗ��������ȡǮ�����ݵ��ӣ��Ե�ʮ�����ӡ��ʷ�
�����Ǹ���ʮ�������ͷ�����������˽�������Ц������ӭ��������
LONG
	);

	set("item_desc",([
		"paizi" :
			"�������ʷ���Ŀǰ�����ṩ�ķ����У�\n"
			"duihuan     �һ�Ǯ�ҡ�\n"
			"qu          ��ȡ��\n"
			"cun         ����Ǯ�ҡ�\n"
			"check       ��ѯ��\n"
	]));

	set("exits", ([
		"north" : __DIR__"zoulang6",
	]));

	set("objects", ([
		__DIR__"npc/yan" : 1,
	]));

	setup();
}
