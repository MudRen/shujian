#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"���ɽ"NOR);
        set("long", @LONG
���ɽ�׳Ʋ�ɽ���ֽ�����ɽ����گʱ��Ϊ����ɽ�������Դ���˴���
�����¹������ţ����ٶ�����������娣�ȫ����ʮ�๫����ɽ��ʮ����
ɽ�壬����������վ���ɡ�ÿ����ɽ��֮���һ��Ϫˮ������Ϫˮʮ������
������̡�ʮ����ɽ�壬���ζ�����ǧ�����ϣ���ߵĴ���ǧһ�ٶ��ף�ɽ
�������겻���Ļ�ѩ��ԶԶ��ȥ�������ɫ��ڣ�����������ġ���ɽѩ����
LONG);
        set("outdoors", "����");
        set("exits", ([
              "eastup" : __DIR__"dc3",
              "westup" : __DIR__"dc3",
             "northup" : __DIR__"dc3",
           "southwest" : "/d/dali/daliwest/nj",
            "eastdown" : "/d/dali/ximen",
        ]));
        set("coor/x",-350);
  set("coor/y",-420);
   set("coor/z",-10);
   setup();
}

void init()
{
	object me = this_player();

	if(me->query_temp("xuncheng")) me->set_temp("dali_xc/18x",1);
}

