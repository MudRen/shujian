// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����·�������ıȽ����롣�����Ͼ����嶾�̵Ĵ��ţ�����ïʢ�Ĺ�ľ
��ƺ�Ǳ��������ɱ����
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"slu2",
                "northup" : __DIR__"wddamen",
                
        ]));
     
        set("objects",([
//                __DIR__"npc/dushe" : 1,

        ]));

       
        set("outdoors", "�置");

        setup();

}
