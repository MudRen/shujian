// caiji@SJ 8/24/2000
// Modify by Lklv 2001.10.16

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG
������һ�̣�Խ��Խ������ת����һ����ɭɭ��ɽ��֮�У��ۼ���������
�����ģ��ƺ��ж������������Ǿ���֮������ǰ��һ��ľ�ƵĴ��ţ�������һ
�ѽ��ƴ���������һ�������ɵĵ�����������������������������ȥ����·
�Աߣ�����һ��ľ�Ƶ����ӣ��������ϵ���д�š�����ȡ������֣��㲻�ɵ�
���ȵذ���һ������ô����������ط���
LONG);
	set("outdoors", "����");
	set("exits",([
		"southwest" : __DIR__"xx1",

	]));
	set("objects",([
		__DIR__"npc/kanshou" : 1,
	]));
        setup();
}

void open_enter1(){
	call_out("open_enter", 2);
}

void close_enter1(){
	call_out("close_enter", 2);
}

void open_enter()
{
	//this open_down() will be called by the NPC "kanshou".
	object downroom;

	if( !(downroom = find_object(__DIR__"duchonggu-out")) )
		downroom = load_object(__DIR__"duchonggu-out");

	set("exits/north", __DIR__"duchonggu-out");
	downroom->set("exits/south", __FILE__);
	message("vision","���ŷ��������������������򿪣������ڿ��Խ�ȥ�ˡ�\n", this_object() );
	message("vision","���ŷ��������������������򿪣������ڿ��Գ�ȥ�ˡ�\n", downroom );

	call_out("close_enter", 20);
}

void close_enter()
{
	object downroom;

	if( !query("exits/north") ) return;

	message("vision","���ŷ��������������������ֹ����ˡ�\n", this_object() );

	if( downroom = find_object(__DIR__"duchonggu-out") ){
		message("vision","���ŷ��������������������ֹ����ˡ�\n", downroom );
		downroom->delete("exits/south");
	}
	delete("exits/north");
}
