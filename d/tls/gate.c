#include <ansi.h>
#include <wanted.h>
inherit ROOM;

void create()
{
        set("short", HIY"��ʥ��"NOR);
        set("long", @LONG
��ʥ���ڴ��������ɽ������֮��������������������ʵ۵ģ���
����λΪɮ�����������ʥ���г��ң���˳�ʥ�±��Ǵ�����ҵļ���
��ȫ������֮���������٣������ֳ�֮Ϊ�����£��������ƻֺ룬�Ϲ�һ
�޷��Ҷ�(biane)�����ﱳ����ɽ�����ٶ�ˮ����ռ��ʤ��
LONG);
        set("outdoors", "������");

        set("item_desc",([
	  "biane" : "\n
            ��������������������������������������������
            ��������������������������������������������       
            ��������     "HIY"��      ʥ      ��"NOR"     ��������
            ��������������������������������������������
            ��������������������������������������������\n\n",
			  ]));	

        set("exits", ([             
               "enter" : __DIR__"road",
               "south" : __DIR__"shanlu",
        ]));

        set("coor/x",-350);
  set("coor/y",-360);
   set("coor/z",20);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "enter" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
