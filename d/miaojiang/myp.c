// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������������У��������������Ǵ󲿷�����������Ρ�һЩ�����
Ѳ������Χ����Ⱥ�������ϰ����ĸ�ʽ����������Ʒ����ЩС���������˶���
�絶����˵�쳣������
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "northeast" : __DIR__"shandao1",
        ]));
        set("objects",([
                __DIR__"npc/miaobing" : 1,

        ]));

      
        set("outdoors", "miaojiang");

        setup();

}
