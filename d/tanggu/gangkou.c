inherit ROOM;
void create()
{
        set("short", "�ۿ�");
        set("long", @LONG
������Ǵ�֮�����˻��Ĵ��Ž�ʯ����������������������һȺȺ��Ÿ
��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻����������Ҵ󴬣�
�������ż����������ˣ��˴��ɶɹ��󺣵��ﺣ����һ�ˡ������������ǣ�
������һ���޼ʵĴ󺣡�
LONG );
        set("exits", ([
                "west" : __DIR__"stdongjie1",
                "northeast" : "/d/sld/xiaolu",
	]));

	set("outdoors", "����");

	set("objects", ([
                "/d/sld/seawar/shilang" : 1,
		__DIR__"npc/wujiang" : 3,
      	]));

	setup();
}
