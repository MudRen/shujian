// /u/dubei/miaojiang
 
 
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������嶾�����ֽ�������ĵط������ڿ����������ڵĳ���ȴ����ԭ
������߰ڷ�������ľ���ӣ�������һ����̴��ľ����ϸ�ĵ�����������
����һ��̴ľ���Ρ���Ϊ��������������һ��С�š�
LONG
        );

        set("exits", ([
             "south" : __DIR__"qiant",
             "northwest" : __DIR__"shef",
        ]));
      
        set("objects",([
                __DIR__"npc/hehongyao" : 1,

        ]));

       setup();

}
