// /u/dubei/miaojiang
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��С���֣����ߺܰ��������ƺ���һЩ���������ĺۼ�����˵�置
�ľ��������׺ݣ������ж����㻹��С��һЩ�ɡ�
LONG
        );

        set("exits", ([
             "east" : __DIR__"mjqj",
              "southdown" : __DIR__"shenchu",
        ]));
      
        set("objects",([
//                __DIR__"npc/jumang" : 1,

        ]));

       setup();

}
