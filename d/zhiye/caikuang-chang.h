// caikuang-chang.h
// by augx@sj  9/10/2001
#include <ansi.h>
#include <job_mul.h>

string* have_items =
	({"qingtong","shengtie","ruantie","lushi","liuhuashi","ruanyin","jintie","shentie","xuantie","hantie",});
string* have_items_c =
	({GRN"��ͭ",YEL"����",YEL"����",HIG"��ʯ",RED"����ʯ",HIW"����",HIY"����",RED"��������",WHT"����",HIC"���꺮����",});

void init()
{
	//object me = this_player();	
	int fib=0;
	int i;
	string biaoji;	
	if(query("outdoors")=="���ݽ���"){		
		biaoji = "���ݵ�̨�����ʾ";
		fib = 9;
	}	
	if(query("show_msg")!=1 && fib>0)
        {
        	biaoji = CHINESE_D->get_title(biaoji)+"    �˵س������\n";
		for(i=0;i<fib;i++)
        		biaoji += "\t"+have_items_c[i]+NOR+"("+capitalize(have_items[i])+")"+"\n";
        	biaoji += "\n\t���ʹ��caikuang xxxx �����ھ�\n";
        	set("show_msg",1);
        	set("long",query("long")+"    ʯ���ϻ���һ�����(biaoji)��\n");
        	set("item_desc/biaoji",biaoji);
        	set("no_fight",1);
        } 
	add_action("do_caikuang","caikuang");	
       //if (wizardp(me) && getuid(me)=="master" && me->query("env/test")==1) add_action("do_wah", "wah");
       //add_action("do_wah", "wah");
}

int do_caikuang(string arg)
{
	object me = this_player() , weapon;
	int level,kuang,delay;

	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tieqiao" )
		return notify_fail("�����װ�����²��ܲɿ�\n");
	if ( !weapon->query("worker_tool"))
		return notify_fail("�����װ�����²��ܲɿ�\n");
	if ( me->is_busy() )
		return notify_fail("����æ���أ�\n");
	if ( !wizardp(me) && (time()<(int)me->query("worker/caikuang")) )
		return notify_fail("��ողɿ�������о��������ۣ�\n");
	level = (int)me->query_skill("caikuang",1);
	if ( level<1 )
		return notify_fail("������Ͳ���ɿ��ǲ�����ѧϰһЩ�ɿ���(caikuang)�����ھ򰡣���\n");

	switch( arg ) {
		case "qingtong": kuang=1; break;
		case "shengtie": kuang=2; if(level<40)  return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "ruantie":  kuang=3; if(level<80)  return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "lushi":    kuang=4; if(level<120) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "liuhuashi":kuang=5; if(level<170) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "ruanyin": kuang=6; if(level<220) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "jintie":   kuang=7; if(level<270) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "shentie":  kuang=8; if(level<330) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		case "xuantie":  kuang=9; if(level<390) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		//case "hantie":  kuang=10; if(level<400) return notify_fail("��Ĳɿ��ܲ�����\n"); break;
		default: return notify_fail("��Ҫ��ʲô��\n"); break;
	}

	if( (int)query("usertime/"+me->query("id")) < 10000 )
		set("usertime/"+me->query("id"),time());
	if( (int)query("user/"+me->query("id")) >= (int)query("kuangshi")
	 || (level>=300 && (time()-(int)query("usertime/"+me->query("id")))>390) )
		return notify_fail("���Ѿ�������������Է��ֵĿ�ʯ�������ˣ�\n");

	message_vision(HIY"$N��ͣ�ĻӶ����£���ʯ������Ѱ�ҿ�ʯ......\n"NOR, me);
//	delay = 8 + random(14);
	delay = 2 + random(2);
	if(wizardp(me) && (int)me->query("env/test")) delay = 2;
	me->start_busy(delay+1);
	call_out("caikuang_finish",delay*2-1,me,kuang);
	return 1;
}
int do_wah(string arg)
{	int i,j;object ob;
	if(!arg) return 0;
	//if(!WORKER_D->querydebug()) return 0;
	if(sscanf(arg,"%d %d",i,j)==2){
		ob = WORKER_D->mater_random(this_player(),i,j);
		if(ob) ob->move(this_player());}
	return 0;
}

void caikuang_finish(object me,int kuangshi)
{
	object tools,obj;
	int level,i=1,improve;
	float updown;
	//< Modified by mxzhao 2005/01/09
	int exp = 0;
	//> Modified by mxzhao 2005/01/09

	if(!objectp(me) || !userp(me)) return;
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("caikuang",1);
	if(level>390) level = 390 + (level-390)*11;

	if ( objectp(tools) && tools->query("id")=="tieqiao" )
		tools->use();

	switch(kuangshi) {
		case 1: i = 40;  break;
		case 2: i = 80;  break;
		case 3: i = 120; break;
		case 4: i = 170; break;
		case 5: i = 220; break;
		case 6: i = 270; break;
		case 7: i = 330; break;
		case 8: i = 390; break;
		case 9: i = 500; break;
		case 10: i = 550; break;
	}
	if ( i>(level*2) ) i=level*2;
	//if ( me->query_temp("user_type") != "worker")
		improve = me->query_int(1)*i/level;
		improve /= 3;
		//20 2 / 10  = 4
	//else
	//	improve = me->query_int()*i/level;
//	improve = me->query_int()*i/level;

	switch(kuangshi) {
		case 1: i = 40;  if(level>100) level=100; break;
		case 2: i = 80;  if(level>150) level=150; break;
		case 3: i = 120; if(level>200) level=200; break;
		case 4: i = 170; if(level>300) level=300; break;
		case 5: i = 220; if(level>400) level=400; break;
		case 6: i = 300; if(level>500) level=500; break;
		case 7: i = 390; if(level>500) level=500; break;
		case 8: i = 550; if(level>500) level=500; break;
		case 9: i = 750; if(level>500) level=500; break;
		case 10: i = 1000; if(level>500) level=500; break;
	}
	updown = WORKER_D->updown(me,"caikuang");
	if( random(level+i) > to_int(i/updown) ) {		
		//write(sprintf("improve : %d\n",WORKER_D->check_impove(me,"caikuang",improve*6,2)));
		WORKER_D->check_impove(me,"caikuang",improve*6,2);
		exp = me->add_exp_combat( random(improve*2/3) ,0,"�ɿ�",1);
		//me->add("combat_exp", random(improve*2/3) *ZY_CAIKUANG_MUL/100 );
		//< Modified by mxzhao 2005/01/09
		//me->add("potential", random(improve/7*3) *ZY_CAIKUANG_MUL/100 );
		me->add("potential", exp*6/7);
		//> Modified by mxzhao 2005/01/09
				
		obj = WORKER_D->mater_random(me,1,kuangshi);
		if(!obj) return;
		
		message_vision(YEL"$N���˺ó�һ��ʱ�䣬�����ҵ�һ��"+obj->query("name")+"��\n"NOR, me);
		if( !obj->move(me) ) destruct(obj);

		if( (int)query("user/"+me->query("id")) <= 0 )
			set("user/"+me->query("id"),1);
		else
			add("user/"+me->query("id"),1);
	}
	else {
		//write(sprintf("improve : %d\n",WORKER_D->check_impove(me,"caikuang",improve*2,2)));
		WORKER_D->check_impove(me,"caikuang",improve*2,2);
		exp = me->add_exp_combat( random(improve/3) ,0,"�ɿ�",1);
		//me->add("combat_exp", random(improve/3) *ZY_CAIKUANG_MUL/100 );
		//< Modified by mxzhao 2005/01/09
		//me->add("potential", random(improve/7) *ZY_CAIKUANG_MUL/100 );
		me->add("potential", exp*1/2);
		//> Modified by mxzhao 2005/01/09
		message_vision(HIY"$N���˺ó�һ��ʱ�䣬����ʲô��û�еõ���\n"NOR, me);
	}
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/caikuang",time()+2+random(2));
}

void reset()
{
	delete("user");
	delete("usertime");
	::reset();
}

