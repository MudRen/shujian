// Room: /d/emei/qianfoan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "ǧ����" NOR);
	set("long", @LONG
�˴��Ǻ鴻ƺǧ���֡�ɽ��Сƺ�ӣ�������͵��ϣ��廷�뻤���������
��ᰣ�Ϫ���ᶣ��ƺ�Ϲ�ľ���裬ͤͤ��ǣ�ɽ����͸������Ʈ�Σ���Ϊ�ľ�
�������˴��������������������������ɣ���ɽ��������Ϊ������ν��ɽ�б�
���꣬�մ�ʪ���¡����������Ϊ��۵ġ��鴻���꡹���˴��������ģ�����
���죬����������;�����ǡ���ʮ�ŵ��ա������¾�������ջ����������
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"jiudaoguai1",
  "north" : __DIR__"heilongjiangzd2",
  "enter" : __DIR__"qianfoandd",
]));
	set("no_clean_up", 0);

	setup();
}
