// Room: /u/xdd/gumu/gchang.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"

void create()
{
	set("short",HIY"���Ϲ㳡"NOR);
	set("long", @LONG
�˴�ԭ�����С������Ǵ��ɹ���ĵط�������Ϸ�Ż�ÿ��������ᣬ��
������ļ���������������ȫ������Ĺ��������ʢ���ƽ̽�ɽ�´˴�������
������������ɭɭ������һƬƽ���ྻ�Ĺ㳡����Ϊ���������ﳣ����ɽ��
���ĳ�����ƽ���ﳣ��������������Ļ�ƣ�Ҳ�к����ڴ���ˣ����������
��С���С�
LONG    
	);

        set("outdoors", "����ɽ");
	set("group", 1);
        set("exits", ([
		"northwest" : "/d/gumu/xiaolu2",
		"southeast" : "/d/gumu/jishi",
        ]));
	setup();
}
