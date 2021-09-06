// feng.c ������
//Modified By ChinaNet
//By 2004/1/11
//�����ļ���
//	feng.c	place.h	chutou.c mine.c	robber.c robber_n.c
//Modified By ChinaNet
//By 2004/1/29 
//�������ǿ�� robber.c,�������ǿ�� robber_n.c,���Ʒ���������minejob_failed,���ӳɹ�������������Ӱ�졣���Ӵ�����ѯ��
//by 2004/3/12 ChinaNet

//add exp By ChinaNet in chutou.c and robber_n.c,fix address bug in place.h,Busy Time ���롣in this file.ÿ50�����ӽ�����in this file.
//by 2004/4/28

//������ʽ��
//by 2004/4/30 by ChinaNet in this file and place.h

//����������check_encour in place.h,fixed check_happy bug in place.h,added log file in this file, place.h ,robber_n.
//by 2004/5/05


inherit NPC;
inherit F_DEALER;

string ask_ylj4();
string ask_ylj5();
string ask_mine_job();
string ask_mine_quality();
string ask_mine_repair();
string ask_mine_product();
string ask_mine_cancle(); 
int ask_mine_times(); 

#include "place.h";

void create()
{
        set_name("������", ({ "feng tiejiang", "feng"}) );
        set("gender", "����" );
        set("age", 53);
        set("long",@long 
���������ǳ��������������������ˣ�˫�۱��̻�޹���ֺ���ϸ��
���Ȳзϣ������³���һ�����ȡ�
���������ѯ���йزɿ�(Mine)�����ϸ�ڡ�	
long);
        set("combat_exp", 50000);

        set("str", 24);
        set("dex", 17);
        set("con", 28);
        set("int", 27);
        set("shen_type", 1);
        set("no_quest", 1);
        set("no_ansuan", 1);
        set("attitude", "friendly");

        set("attitude", "friendly");
        set_skill("dodge", 70);
        set_skill("hammer", 40);
        set_skill("parry", 60);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set("vendor_goods", ({
                __DIR__"obj/hammer",
        }));
        set("inquiry", ([
                "name": "С���շ룬�����˶����ҷ�������",
                "here": "������С�˺��ڵ����ӣ�С�˾�ס����ߵ����ӡ�",
                "��ͷ": "��ͷ... ��Ǹ����ͷ�Ѿ�������...",
                "����": "������С������������������ã�һ��ֻҪ������Ǯ��",
                "����": (: ask_ylj4 :),
                "ʦ��": (: ask_ylj5 :),
                "��Ĭ��" : "�������������С���Ѿ��þ�û����������...",
                "���Ŷݼ�" : "�Ƕ���Сʱ��ѧ�ģ�ƽʱû�½���ư��ˡ�",
                "mine":	(: ask_mine_job :),
                "job":	(: ask_mine_job :),
                "�ɿ�":	(: ask_mine_job :),
                "��ʯ": (: ask_mine_quality :),
                "quality": (: ask_mine_quality :),
                "����": (: ask_mine_repair :),
                "repair": (: ask_mine_repair :),
                "�ӹ�":	(: ask_mine_product :),
                "����": (: ask_mine_cancle :),
                "����": (: ask_mine_times :),
                "����": (: ask_mine_times :),
        ]) );
        setup();
       	carry_object(ARMOR_D("armor/cloth"))->wear();
}

//�ɿ�����
void init()
{
	add_action("do_sell","sell");
	add_action("do_sell","mai");
}

int do_sell(string arg)
{
	object me, ob, obj;
	int value, pot, times, failed_times, exp, mine_skill, encour;
	string msg;
	
	me = this_player();
	ob = this_object();
	times = me->query("minejob");
	failed_times = me->query("minejob_failed");
	mine_skill = me->query_skill("mining",1);
	exp = me->query("combat_exp");
	if( me)	
		if( wizardp(me)) tell_object(me, "times = " + times + ".failed_times = " + failed_times + ".mine_skill = " + mine_skill + ".exp = " + exp + ".\n");
		
	if (!arg || !(obj = present(arg, me)))
		return notify_fail("��Ҫ��ʲô��\n");
	
	if (obj->query("id") != ("kuang shi"))
		return notify_fail("���������������������Ȥ��\n");
	
	if (!me->query_temp("minejob/ask"))
		return notify_fail("�Һ���û����ȥ�ɿ�ʯ�ɣ�\n");
		
	if (!me->query_temp("minejob/find"))
		return notify_fail("�������Լ��ɵ��𣿲�Ҫ���ñ��˵Ķ�����\n");
		
	me->set("job_name","���ɿ�ʯ");	
        me->add("job_time/������",1);
		
        value = obj->query("value")/10;
	

//	��Ϊgold��ȱ��Ŀǰ���ó�ֻ��pot����darken��ҩƷϵͳ��ɺ��ٸĻؼ�gold��
	message_vision("$N��" + MONEY_D->price_str(value) + "�ļ۸�������һ" + obj->query("unit") +
				obj->name() + "��$n��\n", me, ob);

	MONEY_D->pay_player(me, value);
	//me->clear_condition("mine_job",time);
	//me->apply_condition("mine_job",time);

	pot = me->query("potential");
        me->add("combat_exp", value/100);
	if (wizardp(me)) 
		tell_object(me,"����ʯ�ļ�ֵ�ǣ�" + value + "��\n");
	message_vision("$N��һ" + obj->query("unit") + obj->name() + "����$n��\n", me, ob);
        tell_object(me, "��õ���" + CHINESE_D->chinese_number(value/100) + "��ʵս���顣\n");
	
	if( (times % 30) == 0 && failed_times < 200)
	{
//����������ࡣ
		encour = check_encour(me);
		msg = check_happy(me, obj, encour);
		tell_object(me,msg);
	}

        if (me->query("potential") > me->query("max_pot") * 8)
	{

                tell_object(me,"��ϧ���ź����ܾ������ޣ�����ʧ��"+chinese_number( value / 100 - (me->query("max_pot") * 8 - pot))+"��Ǳ�ܡ�\n");
		me->set("potential", me->query("max_pot") * 2);
	}

	if(obj->query("level") == "hard" || obj->query("level") == "veryhard")
	log_file("job/minejob",sprintf("%s %s(%s)sell��%s�����%s��\n",
		ctime(time())[4..19],me->name(1),capitalize(me->query("id")),obj->query("level"),obj->query("name")));
	me->delete_temp("minejob");
	destruct(obj);
	return 1;
}
string ask_mine_job()
{
	object me,obj,mine,robber;
	string place_level;
	string str,strb,strc;
	string job_type;
	int time,killer;

	me = this_player();
	place_level = "normal";
	job_type = "����";
	killer = 0;

	if (me->query_temp("minejob/ask"))
		return "���Ҵ��ǲ��ǣ�����ȥ������";

	if (me->query_condition("mine_job") > 0)
		return "������꿪�ɿ�ʯ�����ٵȵȰɡ�";

	if( me->query_condition("job_busy"))
		return "��������æ�������������أ�";

	if (me->query_con() <= 30)
		return ("�������������Գ����������Ͷ���");

//�жϵص�����ף����ɴ��жϳ���ʯ������������
	place_level = check_level(me);
//�ж��Ƿ������١�
	killer = check_killer(place_level);

	str = get_address(place_level,me);//��ȡ�ص�C�ļ�
	strb = get_place(str);		//ȡ�õ�����Ϣ
	strc = load_object(str)->query("short");
	time = random(5)+ 5;
	
//Add by ChinaNet 2004/2/10
	if (random(20) > 10 && me->query_skill("caikuang",1)>=80 )
		job_type = "����";
	
	if (job_type == "����")
	{
		me->set_temp("minejob/area",str);
		me->set_temp("minejob/areab",strb);
		me->set_temp("minejob/areac",strc);
		me->set_temp("minejob/ask",1);
		me->set_temp("minejob/level",place_level);
		me->set_temp("minejob/times",0);
		me->set_temp("minejob/type",job_type);
		me->set("job_name","���ɿ�ʯ");
		me->apply_condition("job_busy",time);
		me->apply_condition("mine_job",time + 5);

		if (wizardp(me))
			tell_object(me,"��ȡ�ص��ǣ�"+str+"    ����λ�ã�"+strb+"    �����Ѷȣ�"+place_level+"��\n");
		
        	if ( !objectp( present("chu tou", me)) ) 
        	{
                	obj = new(__DIR__"obj/chutou.c");
                	obj->set("user",me->query("id"));
                	obj->move(me);
	                message_vision("������ת�������ó���һ�ѳ�ͷ��$N��\n",me);
        	}
			
//Add by ChinaNet 2004/2/1 
//ɱ��
		if(place_level == "hard" || place_level == "veryhard")
		log_file("job/minejob",sprintf("%s %s(%s)����%s�����ʯ���ص��ļ���%s������%s��\n",
			ctime(time())[4..19],me->name(1),capitalize(me->query("id")),place_level,str,strb));

		if (killer)
			{
				me->set_temp("minejob/killer",1);
				return "��λ" + RANK_D->query_respect(me) + "�������ھ�ȥ" + strb + strc + "ȥ��һ�������ܻ����ջ�ǰ·���գ�һ�ж��С�ġ�\n";
			}
		return "��λ" + RANK_D->query_respect(me) + "�������ھ�ȥ" + strb + strc + "ȥ��һ�������ܻ����ջ�\n";
	}
	
//add by ChinaNet 2004/2/10
//���ٿ�ʯ
	if (job_type == "����")
	{
		me->set_temp("minejob/area",str);
		me->set_temp("minejob/areab",strb);
		me->set_temp("minejob/areac",strc);
		me->set_temp("minejob/ask",1);
		me->set_temp("minejob/level",place_level);
		me->set_temp("minejob/times",0);
		me->set_temp("minejob/type",job_type);
		me->set("job_name","���ɿ�ʯ");
		me->apply_condition("job_busy",time);
		me->apply_condition("mine_job",time + 10);
		
		mine = new(__DIR__"obj/mine.c");
		mine = settings_mine(place_level, mine);
		robber = new(__DIR__"obj/robber_n.c");
		robber->set_temp("target",me->query("id"));
		robber->set_temp("minejob/level",place_level);
		robber->move(load_object(str));
		robber->set("long",robber->query("long")+"���ո��յ���Ϣ��"+me->query("name")+"("+me->query("id")+")����Я����"+mine->query("name")+"������Ȥ��\n�����ŵĴ˴�������С�Ľ䱸�Բ���ȫ��\n");		
		mine->add("value",random(50000)+50000);
		mine->move(robber);		
		if(place_level == "hard" || place_level == "veryhard")
		log_file("job/minejob",sprintf("%s %s(%s)����%s�����ʯ���ص��ļ���%s������%s��Npc:%s(%s)\n",
			ctime(time())[4..19],me->name(1),capitalize(me->query("id")),place_level,str,strb,robber->query("name"),robber->query("id")));
		if (wizardp(me))
			tell_object(me,"��ȡ�ص��ǣ�"+str+"    ����λ�ã�"+strb+"    �����Ѷȣ�"+place_level+"��\n");
		
		return "����"+robber->query("name")+"��" + strb + strc + "������˽��ʯ����ȥ����취�����˽ƻ��׺ݣ����С�ġ�\n";		
	}
	return "�������͹�˼�С�";
}

string ask_mine_cancle()
{
	object obj, me = this_player();
	
	if ( !me->query_temp("minejob") )
		return "��ûҪ���񣬷���ʲô��\n";
//���Ʒ�����
	if( me->query("menejob_failed") >= 200 && random(5) == 1)
		return "�����ұ��ˣ�������ô����£���ȥ��\n";
		
	if (obj = present("chu tou", me))
		destruct(obj);
	me->delete_temp("minejob");
        me->add("minejob_failed",1);
   me->apply_condition("mine_job",10);
	me->set("job_name","���ɿ�ʯ");	
	return "��Ȼ�������ˣ����߰ɡ�\n";
}

int ask_mine_times()
{    
	object me,ob;
	int i,j;
	me = this_player(); 
	ob = this_object();
	
    i = me->query("job_time/������");
	j = me->query("minejob_failed");
	
	if( !i )
		return notify_fail("��ɹ�ʯͷ��?"); 
		
	if( !j )
		message_vision("$N����$n�����룬˵������Ŀǰ������" + chinese_number(i) + "������\n", ob,me);
	else 
		message_vision("$N����$n�����룬˵������Ŀǰ������" + chinese_number(i) + "�����񣬷�����" + chinese_number(j) + "�Ρ�\n", ob,me);
	return 1;
}

string ask_mine_quality()
{
	object me;
	me = this_player();
	return "��λ" + RANK_D->query_respect(me) + "����ʯ������֤���������У������ڴ���\n";
}
string ask_mine_repair()
{
	object me;
	me = this_player();
	return "��λ" + RANK_D->query_respect(me) + "����������������������У������ڴ���\n";
}

string ask_mine_product()
{
	object me;
	me = this_player();
	return "��λ" + RANK_D->query_respect(me) + "����������������������У������ڴ���\n";
}

int accept_object(object me, object ob)
{
        object sword;
        if (ob->query("id") =="mowen xuantie") {
            if(me->query_temp("ylj/step4")) {
            	me->delete_temp("ylj/step4");
            	me->set_temp("ylj/step5", 1 );
                say("������˵����������ī���������ô���������Ҫ�õ��һ��������Ĳ���֮�ܣ�δ��ʦ����ɣ�����......\n");
	        return 1;
              	}
	        else say("�ⶫ����Ҫ��û�á�\n");
        }
        else if (ob->query("id") == "ling pai") {
             if(me->query_temp("ylj/stepend") && environment(this_object())->query("short") == "������" ) {
                sword = unew(BINGQI_D("sword/youlong-jian"));
        	if( clonep(sword) ) {
        		sword->move(me);
	        	me->delete_temp("ylj/stepend");
                	say("��Ĭ���ϲ������������Ϊ����ֻ�о��������Ա����......\n");
		        return 1;
                	}
              	}
		else say("�ⶫ����Ҫ��û�á�\n");
        }
	return 0;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

string ask_ylj4()
{
        object me;
        me = this_player();
        if ( !me->query_temp("ylj/step3") )
        	return "���ں�������Լ���ȥȡ�ɡ�\n";
        me->delete_temp("ylj/step3");
        command("look "+me->query("id"));
       	me->set_temp("ylj/step4",1);
	return "��λ" + RANK_D->query_respect(me) + "���Ƿ���������Ĳ��ϣ�\n";
}

string ask_ylj5()
{
        object me, obj;
        me = this_player();
        if ( !me->query_temp("ylj/step5") )
        	return "����ʦ������䣬�ɲ���˵�������ġ�\n";
        me->delete_temp("ylj/step5");
	obj = new(__DIR__"obj/ling");
        if( clonep(obj) ) {
        	obj->move(me);
	       	me->set_temp("ylj/step6",1);
		return "�ұ����һ������ӣ�����ʦ���ҩʦ��ʧ�˾����澭��һ\n
ŭ֮�°�����ʦ�ֵܵ��ȽŴ�ϣ������ʦ�ţ��þ�û��ʦ���ˣ���֪ʦ���\n
������Ρ�����ʱ��Ļ����ܷ�Ϊ����һ���һ�����������һ�������ǵ���ʦ\n
���͸��ҵģ�ƾ������ݷ���ʦ����˵Ĭ����ʱ�޿̲������������˼�......\n";
       	}
       	return "����ʦ������䣬�ɲ���˵�������ġ�\n";
}
