// �յ�.c
// �յ�
inherit ROOM;
void create()
{
	set("short","�ּ�յ�");
	set("long",@long
�������ּ��һ��յأ�һ�߽�����Ϳ����ŵ�һ��ŨŨ���ۻ�ζ�˱Ƕ�
�����ڿյ��������������ݣ����ӵ�ǽ�ڡ��ݶ�������ڴ�С�Ĵ������࣬��
�����Ǽᶨ���ݺ��е�ɽϪ��ɽ���¡�
long);
	set("exits",([
	    "north" : __DIR__"treen2",
           "south" : __DIR__"trees2",
           "northup" : __DIR__"sanroad1",
           "enter" : __DIR__"lgxroom",
]));

	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",410);
   set("coor/z",0);
   setup();
       call_other( "/clone/board/sld_b", "???" );
}
	    	
