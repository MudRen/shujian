inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц
�������������������������һƬ��������Ķ��䣬�㲻����Գ��������
�ʹ�ͣ������һ�������ݵĳ���������ɫ��ʱ��ʹ���Ŀ���������ʱ�˿�ֻ
���������Ȼ�����ľ�ɫ��Ϊһ�塣�����￴ȥ�������ϳǵĽ־���һƬ��
�֡��ڽֵĶ�������һ����ݣ�������ȥ��һ������԰�֡�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"northeast" : __DIR__"chaguan",
"southwest" : __DIR__"shuyuan",
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"baodaiqiao",
"west" : __DIR__"jubaozhai",
                "east" : __DIR__"shizilin",
	]));

	set("coor/x",110);
  set("coor/y",-240);
   set("coor/z",0);
   set("incity",1);
	setup();
}

