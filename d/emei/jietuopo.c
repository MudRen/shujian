// Room: /d/emei/jietuopo.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "������" NOR);
	set("long", @LONG
�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š��������ˣ���������
Ȫ�������������������������޽�٣��ļ����ѡ�����һ�����ã�����һƬ��
�֡�����ɽϪ�����ʵ������µ����档
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
	  "west" : __DIR__"guanyinqiao",
	  "eastdown" : __DIR__"milin2",
]));
	set("no_clean_up", 0);

	set("coor/x",-230);
  set("coor/y",-130);
   set("coor/z",30);
   setup();
}
