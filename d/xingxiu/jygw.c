// Room: /d/xingxiu/jiayuguan.c
// June 97
// by pishou

inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", "������������");
        set("long", @LONG
���ǳ��������Ĺذ������������š��������ͳ������ˣ��������о���פ
������ʱ�����������ˡ���С�����������뿪���Ƿ�֮�ء�����������������
���ġ�˿��֮·������һ̤������ĵ����̲�ס�ع�ͷ������һ�¼����ء�����
���²�ɣ�����ڲ�ס���ķ�ɡ�Ⱥɽ����֮�£����������ۻ롣���ŵ�ǽ������
��һֽ��ʾ(gaoshi)��
LONG);

        set("outdoors", "yili");
        set("exits", ([
                "east" : __DIR__"jyg",
                "west" : __DIR__"silk",
        ]));

         set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("objects", ([
                __DIR__"npc/bing1" : 2,
                __DIR__"npc/wujiang1" : 1,               
        ]));
        set("coor/x",-220);
  set("coor/y",70);
   set("coor/z",-10);
   set("coor/x",-220);
  set("coor/y",70);
   set("coor/z",-10);
   set("coor/x",-220);
 set("coor/y",70);
   set("coor/z",-10);
   setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\nȫ��ͨ����\n";
}

#include "/d/xingxiu/job2.h";