// lgxys.c
// ½������ҩ��
inherit ROOM;
void create()
{
	set("short","ҩ��");
	set("long",@long
һ�߽�������ӣ����ŵ���Ũ�Ĳ�ҩζ��ֻ�����￿ǽ��һ��ҩ�񣬴���
���£������ң�һ���طֳ�����ǽ�ϣ����£�Ҳ��������ҩ�ݣ�����
��½������ҩ�ĵط���
long);
	set("exits",([
	    "west" : __DIR__"lgxroom",
]));
set("objects",([
__DIR__"npc/obj/yaogui" : 1,
]));
	//set("yaozhong",15);
	set("coor/x",500);
  set("coor/y",410);
   set("coor/z",10);
   setup();
}
	
void reset()
{
        object 		*inv;
        object 		con, item;
	 int		i;	

        ::reset();
	//set("yaozhong",15);
        con = present("yaogui", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) < 10) {
	     for(i=4-sizeof(inv); i>=0; i--)
            {
        	item = new(__DIR__"npc/obj/sheyao");
        	item->move(con);
            }
        }
}    	

void init()
{    
     add_action("do_search", "search");
}

int do_search(string arg)
{
	object me=this_player();
	object ym;
	string* type5=({"��","��","ˮ","ľ","��"});

	if(!me->query_temp("yaozhong",1))
	{
		tell_object(me,"ͻȻ��������������̵Ļ��̵��ӣ������ȵ������ڸ�ʲô����������͵������Ȼ��һ���Ұ������裡...\n");
		me->move("/d/sld/kongdi");
		me->unconcious();
		return 1; 
	}
	if((arg!="����") && (arg!="corner") && (arg!="ǽ��") && (arg!="�ݽ�"))
		return 0;
	if(me->query("jingli")<50)
		return notify_fail("������̫���ˣ�����Ϣһ�°ɡ�\n");
	else
		me->add("jingli",-50);
	/*if(!query("yaozhong"))
		return notify_fail("�����˰��죬ʲô������û���ҵ���\n");*/
	if((time()-me->query("yztime"))>1200)
	{
		me->set("yztime",time());
		me->set("findyz",0);
	}
	if(me->query("findyz")>8)
		return notify_fail("�����˰��죬ʲô������û���ҵ���\n");
        if(random(10)>7)
	{
		ym=new("/d/sld/npc/obj/yaozhong");
		if(!ym)
			return notify_fail("�����˰��죬ʲô������û���ҵ���\n");
		ym->set("5type",type5[random(sizeof(type5))]);
		if(!ym->move(me))
			ym->move(this_object());
		message_vision("$N���˰��죬�ҵ�һöҩ�֡�\n",me);
		//add("yaozhong",-1);
		if(!me->query("findyz"))
			me->set("findyz",1);
		else
			me->add("findyz",1);
		return 1;
	}
	return notify_fail("�����˰��죬ʲô������û���ҵ���\n");
}
