// Room: /d/emei/heilongjiangzd2.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "������ջ��" NOR);
	set("long", @LONG
������ջ���غ���������������һɽ�п������²������γ�һ��������ߣ�
���Ｘ���׵���Ͽ��������Ͽ��������ջ���ʹ���խ�İ���Ͽ��ת�۴�������
���ھ����ϡ�����ջ���ϣ�ֻ����խ��Σ�������������������ɽ����������
����ͷ���������϶���¿������ϡ�������쿪��ͼ�ġ�һ���졹��ջ����ͨ
ǧ���֣�����������
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
  "north" : __DIR__"heilongjiangzd",
  "south" : __DIR__"qianfoan",
]));
	set("no_clean_up", 0);

	setup();
}
