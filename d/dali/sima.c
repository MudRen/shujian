// By River 98/12/
inherit ROOM;

void create()
{
	set("short", "˾����");
	set("long", @LONG
�����ÿ����������ڸ���һ�б����ܣ���ǹ��ꪽ�ȫ���鰸֮�����
�������ڼ��ϣ����л�Ƥ��Ƥ�̵أ�һ����֮����ٹ��á��������Ǵ����˾
���ǵ�˾����˾���������񣬴����ľ�������Ϊ������ı�����Ҫ����߾�
�������ΰ����ѡ�
LONG
	);        
	set("exits", ([
           "east" : __DIR__"yamen",            
	]));

        set("objects", ([              
               __DIR__"npc/sima" : 1,
        ]));

	set("coor/x",-340);
  set("coor/y",-370);
   set("coor/z",-20);
   setup();
}
