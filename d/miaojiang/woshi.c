// /u/dubei/miaojiang

 
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������嶾�̽��������ֵ����ң����ڳ������,�����˱�.���԰ڷ��ż�
���ʻ���ǽ�Ϲ���һ�ѱ�����
LONG
        );

        set("exits", ([
             "north" : __DIR__"shef",
        ]));
      
        set("objects",([
                __DIR__"npc/hets" : 1,

        ]));

       
      setup();

}
