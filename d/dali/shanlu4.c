// Room: ɽ· 4
// bbb 1997/06/11
// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
��������һ����᫲�ƽ��·��,��������ɭɭ��ԭʼ����,��ʱ����һ����
��Ұ�޽���,ͷ����һЩ��֪����С����������ȥ��ǰ���·��������,������
�����ⲻԶ��,·����һ��ʯ��(shibei),����һЩ�֡�
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"dadao1",
		"north" : __DIR__"shanlu3",
        ]));
	set("item_desc", ([ /* sizeof() == 1 */
	    "shibei" : "���Ǵ��Ρ����������Ľ籮��\n"
        ]));
	set("no_clean_up", 0);

	set("coor/x",-310);
  set("coor/y",-320);
   set("coor/z",-20);
   set("coor/x",-310);
  set("coor/y",-320);
   set("coor/z",-20);
   setup();
}
