// /u/dubei/miaojiang
// by dubei
 
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������嶾�̴�ű����ĵط����������ϰڷ��Ÿ�ʽ�������������嶾����
Ȼ�����ö����������书����Ҳ�ж���֮����
LONG
        );

        set("exits", ([
             "west" : __DIR__"qiant",
        ]));
      
        set("objects",([
                __DIR__"npc/jiaozhong" : 1,
                BINGQI_D("changjian") : 1,
                BINGQI_D("zhujian"): 1,
        ]));      

        setup();
}
