// Room: /d/emei/heilongjiangzd.c

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
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"heilongjiangzd2",
  "northeast" : __DIR__"qingyinge",
]));
	set("no_clean_up", 0);

	setup();
}
