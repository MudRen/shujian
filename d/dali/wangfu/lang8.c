// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ�����Կ����������ľ���ݡ������ǹ�ȥ��һ��С��԰��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */            
            "northeast" : __DIR__"lang6",            
	    "west" : __DIR__"huayuan",
        ]));
	 
	set("coor/x",-280);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();
}
