// Room: /d/city/dangpu.c
// Update by lsxk@hsbbs 2007/7/19

#include <ansi.h>;

inherit ROOM;

mapping *special=({
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
([]),
});


void getspec();

void create()
{
	set("short", "����");
	set("long", 
"����һ������������ƽ���Ƶ����ֺŵ��̣�һ���ĳ߸ߵĹ�̨���������\n"+
"ǰ����̨�ϰ���һ������(paizi)�� ��̨�����ŵ��̵��ϰ壬һ˫���������\n"+
"���������´������㣬��˵�������ڴ���������"+HBGRN+HIG+"�齣ͨ��"+NOR+"����\n"
);
	set("no_fight",1);
	set("no_sleep_room",1);
	set("objects", ([
           __DIR__"npc/huang" : 1,
           __DIR__"npc/mm2" : 1,
	]));
	set("exits", ([
         "north" : __DIR__"guangchangnan",
	]));

	set("coor/x",110);
  	set("coor/y",-30);
   	set("coor/z",0);
	getspec();
	setup();
}

void init()
{
    object me = this_player();
    object obj;

    if(!objectp(me)) return;
/*
    if(!present("tongbao xiang", me) && !random(100) ){
        message_vision(HIC"ͻȻ��$N���ִӵ��̹�̨�ϵ�����һ������������æµ���ϰ�ͻ���Ƕ�û���֡�\n$N��æ�������������Լ����ϡ�\n"NOR,me);
        if(!wizardp(me))
        me->add_busy(3+random(3));
        if(!present("tongbao xiang",environment(me)) ){
            obj = new("/clone/gift/credit_box");
            obj->move(me);
        }
    }
*/
	add_action( "do_exchange", "duihuan" );
	add_action( "do_look", "look" );
}

void getspec()
{
	mixed *file;
	int i;
	object ob;
	string tpw;
	
	file = get_dir("/clone/spec/");

	if( !sizeof(file) ) return notify_fail("�Ҳ����κ���Ʒ \n");
	for( i = 0; i < sizeof(file); i++ )
	{	tpw = "";
                file[i] = "/clone/spec/" + file[i];
                if( file_size(file[i]) < 0 ) continue;
		ob = new(file[i]);
		
		if(!objectp(ob)) continue;		
		if(!ob->query("credit")) continue;		
		
		if (!ob->query("rest"))
			tpw = "��";		
		else
			tpw = "ÿ��"+chinese_number(ob->query("rest"))+"��";	
		special[i]=([
			"value"		:	ob->query("credit"),
			"name"		:	ob->query("name"),
			"id"		:	ob->query("id"),	
			"desc"		:	ob->query("desc"),	
			"degree"	:	ob->query("degree"),
			"tpw"		:	tpw, 
			"file"		:	file[i]
			 ]);
		destruct(ob);	
	}
}


int do_look(string arg) 
{       
	object me = this_player();
	int i;
        
	if(me->is_busy()) 
		return notify_fail("����æ���ء�\n");
        	
 
        if (arg == "paizi" ){   
	        write(query("special"));
	        write("��ƽ���ף��������ۡ�\n");
	        write("�����������ɡ��齣ͨ�����������齣ͨ���һ������Ƽ��������£�\n");
                write("��������������������������������������������������������������������������������������������������������������\n");
                write(sprintf("�� %-25s  %-45s  %-10s %-12s %-7s��\n", "��������","��������","���ô���","ʹ������","ͨ��" ));
                write("�ǩ�����������������������������������������������������������������������������������������������������������\n");
	        for (i=0;i<sizeof(special);i++) {
	        	 if (!special[i]["value"]) continue;
          write(sprintf("�� %-25s  %-46s %-10s %-12s "+HIY+"%-7d"+NOR+"��\n", special[i]["name"]+"("+special[i]["id"]+")",special[i]["desc"],chinese_number(special[i]["degree"])+"��",special[i]["tpw"],special[i]["value"] ));
	        }
                write("��������������������������������������������������������������������������������������������������������������\n");
	        write("��ʹ�ã�duihuan xxxx��ָ�����һ���á�\n");
		return 1;
	}     
	return 0;
}

int do_exchange(string arg) 
{
   int i,j,k;
   object card,ob,me = this_player();
	
	if(me->is_busy()) 
		return notify_fail("����æ���ء�\n");
  		
	if(!arg)
		return notify_fail("����һ�ʲô��\n"); 
  		
	for (i=0;i<sizeof(special);i++)
	if (arg == special[i]["id"])  
		j=i+1;	
	if(!j)
		return notify_fail("����û������һ�������\n");
        
        if (me->query("quest/bwdh/card_winner") && present("vip card", me)
          &&special[j-1]["value"]*(int)me->query("quest/bwdh/card_winner")>me->query("SJ_Credit")*100)
           return notify_fail("�Բ��������е�ͨ�������һ�"+special[j-1]["name"]+"��\n");
        else if (special[j-1]["value"]>me->query("SJ_Credit"))
		return notify_fail("�Բ��������е�ͨ�������һ�"+special[j-1]["name"]+"��\n");
        
	ob = new(special[j-1]["file"]);
	if(!objectp(ob))
		{return notify_fail("ϵͳ��������ϵWIZ��\n");}
		
   if(me->query("quest/bwdh/card_winner") && present("vip card",me)){
    card = present("vip card",me);
   me->add("SJ_Credit",-(special[j-1]["value"]*(int)me->query("quest/bwdh/card_winner")/100));
   me->add("SJ_Credit_Used",(special[j-1]["value"]*(int)me->query("quest/bwdh/card_winner")/100));
   k = special[j-1]["value"]*(int)me->query("quest/bwdh/card_winner")/100;
   message_vision(sprintf(HIC"%sһ���ͳ������%s"HIC"���⵱���ϰ�ָ��ָ%s"HIC"�����������ˣ�����������\n"NOR,me->query("name"),card->query("name"),special[j-1]["name"]),me);
   message_vision(sprintf(HIG"�����ϰ�ӹ�%s"HIG"һ��������Ŀ���%s,��æ������ԭ���Ǳ�������������Ƭ�̣������������ף�\n"NOR,card->query("name"),me->query("name")),me);
   }
   else{
	me->add("SJ_Credit",-special[j-1]["value"]);
        if(special[j-1]["id"]!="baochao" && special[j-1]["id"]!="da baohuo" ) me->add("SJ_Credit_Used",special[j-1]["value"]);
   }
   ob->move(me);
   if(me->query("quest/bwdh/card_winner") && present("vip card",me)){
   message_vision(sprintf("�����ϰ�ߺ��һ������VIP�ͻ�:%s�һ����Ƽ�����%s��"+me->query("quest/bwdh/card_winner")/10+"���Żݣ�����%s���齣ͨ������\n",me->query("name"),special[j-1]["name"],chinese_number(k)),me);
    }
   else
	message_vision(sprintf("�����ϰ�ߺ��һ������%s�һ����Ƽ�����%s������%s���齣ͨ������\n",me->query("name"),special[j-1]["name"],chinese_number(special[j-1]["value"])),me);
	tell_object(me,"��Ŀǰ��ʣ"
		+ chinese_number(me->query("SJ_Credit"))+"���齣ͨ�������Ѿ��ۼ�������" 
		+ chinese_number(me->query("SJ_Credit_Used")) +"���齣ͨ����\n");
	log_file( "static/CREDIT",sprintf("%s(%s) | ����%s | ʣ:%s | ��:%s | �ۼ�:%s.\n", me->name(), me->query("id"), special[j-1]["name"],chinese_number(me->query("SJ_Credit")),chinese_number(special[j-1]["value"]),chinese_number(me->query("SJ_Credit_Used"))));
        me->start_busy(1);
		
	return 1; 
}
