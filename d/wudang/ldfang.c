// Room: /d/wudang/liandanfang.c
// Update by lius 99/8
// Modify By River@SJ
#include <ansi.h>
#include <job_mul.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǽ�ҩ�������Ĵ��ݣ������ܶ����˸�ʽ������ҩ�ģ������м�ڷ�
��һֻ�����õ�����ͭ��(tongding)��ǽ�߻��и��ֹ��ߣ���ҩ����ҩ....һ
Ӧ��ȫ����ͯ����ȫ���ע��Э�������ߣ��ȷ絣ˮ��һ�ж���Ȼ������Ȼ
��ѵ�����ء���Ϊ����������Ե�ʣ��������ļ��紺��
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang2",
        ]));

        set("objects",([
                CLASS_D("wudang") +"/yudaiyan" : 1,
                __DIR__"npc/daotong" : 1,
        ]));

        set("item_desc", ([
                "tongding" : "    ��������ͭ���ɵ�����ͭ������Լ���ٶ��������о���Ϸ��\n"+
                             "��ͼ�������ڻ������������������Ľ�Ҫ��ͷ! Ϊ�˱��ֻ��ƣ�����\n"+
                             "��ͣ���򶦿���(shan)�硣\n",
        ]));

        set("dan_count", 3);
        setup();
}

void init()
{
        add_action("action", ({
                "du",
                "lian",
                "practice",
                "study",
        }));
        add_action("do_quit", "quit");
        add_action("do_kanshou", "kanshou");
        add_action("do_leave", "leave");
        add_action("do_shan", "shan");
        add_action("do_yan",({"yan", "mo"}));
        add_action("do_lianyao", ({"lianyao","aoyao"}));
        add_action("do_kan", ({"kan","look"}));
        add_action("do_yunqi", "yunqi");
        add_action("do_qilu", "qilu");
}

int action()
{
        write("�����صأ�������ˣ�\n");
        return 1;
}

int do_quit()
{
        write("���ﲻ���˳���Ϸ��\n");
        return 1;
}

int do_shan(string arg)
{
	mapping fam;
        object me;
        int costj, costq;
        me = this_player();

        if( me->query_temp("wd_job1")) 
            {write("�㻹��ר�Ŀ���ͭ���ɣ�\n");return 1;}

        if (me->is_busy()) return notify_fail ("��������æ���أ�\n");

        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר�ĸɻ\n");

        if ( ! arg || arg != "tongding" ){
      	    message_vision("$N���˰��֣�������������\n",me);
            return 1;
        }
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
               return notify_fail("���뱾�����������������ڴ��˷�������\n");

        costj = 1000 / (int)me->query("con");
        costj = random(costj);
        costq = 1500 / (int)me->query("str");
        costq = random(costq);

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
             message_vision("$N�������ͣ�һ������ͷྵ���¯�ϣ�\n",me);
             me->unconcious();
             return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->receive_damage("qi", costq);       

        tell_object(me,"�����������������Ż�\n");

        if ( (int)me->query_skill("cuff", 1) < 31){
              write(HIY"���ֱ���������������֮���ƺ��Ի���ȭ����Щ����\n"NOR);
              me->improve_skill("cuff", (int)(me->query("int") / 2));
        }
        if ( (int)me->query_skill("hand", 1) < 31){
              write(HIY"���ֱ���������������֮���ƺ��Ի����ַ���Щ����\n"NOR);
              me->improve_skill("hand", (int)(me->query("int") / 2));
        }
        return 1;
}

int do_kanshou()
{
       mapping fam;
       int exp;
       object me;
       object ob = this_player();

       if(!present("yu daiyan",  environment(ob) ) )
                return notify_fail("ʲô��\n");

       me = present("yu daiyan",  environment(ob) );
       fam = ob->query("family");
       exp = ob->query("combat_exp");

       if(ob->is_busy()) return notify_fail("��������æ���ء�\n");

       message_vision(CYN"$N�뿴��ͭ����¯��\n"NOR,ob);

       if (!fam || fam["family_name"] !="�䵱��")
             return notify_fail(GRN"����Ҹ����㣺"+RANK_D->query_respect(this_player())+"�뱾�������������ҿ����ǲ�����������ˣ�\n"NOR);

       if (exp < 100000)
             return notify_fail("���ʵս���鲻�㣬������ȥ��ҩ�ɣ�\n");

       if (exp > 500000)
             return notify_fail("�㶼��ô�����ˣ�����ȥ���������������ɣ�\n");

       if(ob->query_condition("wd_job") > 0 )
             return notify_fail("����æ�������������ء�\n");
/*
       if(ob->query("job_name") == "����ͭ��"){
            message_vision(CYN"�����˵����"+ob->name()+"���㻹����ȥЪϢƬ�������ɣ�\n"NOR,ob);
            return 1; 
 }

*/
       if(ob->query_condition("job_busy") >= 1){
            message_vision(CYN"�����˵����"+ob->name()+"���㻹����ȥЪϢƬ�������ɣ�\n"NOR,ob);
            return 1; 
       }
/*
       if( me->query("guard_count") >= 3){
            message_vision(CYN"�����˵�������������Ѿ����ˣ�"+ob->name()+"���㻹��ȥ���������������ɣ�\n",ob);
            return 1;
       }
*/
       if (ob->query_temp("wd_job1"))
             return notify_fail("�����ڿ���ͭ����\n");

        me->add("guard_count",1);
        ob->set_temp("wd_job1",1);
        ob->set_temp("apply/short", ({HIC"ͭ������"NOR+" "+ob->name()+"("+capitalize(ob->query("id"))+")"}));
        message_vision(CYN"�����˵�����ðɣ�"+ob->name()+"������������ʱ���������ȱ���֡�\n"NOR,ob);
        message_vision(CYN"�����˵������ͭ����¯���䵱��������һ��ҪС�Ŀ�����\n"NOR,ob);
        call_out("give_reward",240+random(60),ob);
        ob->add_busy(1);
        ob->set("job_name", "����ͭ��");
        call_out("do_attack",120+random(80),ob);
        if(random(10) > 2) {
		call_out("do_attack",20+random(40),ob);
		return 1;
        }
        return 1;   
}

int do_leave(object ob)
{
        object me;
        ob = this_player();
        me = present("yu daiyan",  environment(ob));

        if( ob->query_temp("wd_job1")<1 )
            return notify_fail("�㲢û���ڿ���ͭ����\n");

        ob->delete_temp("wd_job1");
        if (!me) return notify_fail("���������Ҳ���ʱ�����ɲ��С�\n");
        me->add("guard_count",-1);
        if (me->query("guard_count") < 0) me->set("guard_count",0);
        ob->delete_temp("apply/short");
        ob->apply_condition("job_busy",16);//add by caiji@SJ
        // busy must > 15,because of a bug
        ob->apply_condition("wd_job",16);// add by caiji@SJ
        //busy must > 15,because of a bug
        message_vision(CYN"$N����������ֿ���ͭ����¯������\n"NOR,ob);
        message_vision(CYN"�����˵����������"+ob->name()+"����Ȼ��ɲ�����Ҳ����ǿ�㣬�´κúøɰɣ�\n"NOR,ob);
        return 1;
}

int do_attack(object ob)
{
        mapping skills;
        string *sk;
        int exp,i,lv;
        object att;
        if(!ob || !ob->query_temp("wd_job1")) return 1;
        if(!present("yu daiyan",environment(ob))) {
             tell_object(ob,"����ʧ�ܡ�\n");
             ob->delete_temp("wd_job1");
             return 1;
        }
        exp = ob->query("combat_exp");
        lv = ob->query("max_pot") - 90 + random(10);
        lv = ob->query("max_pot") - 110 + random(10);
        if( ob->query("combat_exp")<500000) lv-=20;
        else if (ob->query("combat_exp") < 1000000) lv-=15;
        else if (ob->query("combat_exp") < 1500000) lv-=10;
        att = new(__DIR__"npc/attecker");
        att->set("qi",(int)ob->query("qi"));
        att->set("max_qi", (int)ob->query("max_qi") );
        att->set("eff_qi", (int)ob->query("max_qi") );
        att->set("jing",(int)ob->query("jing"));
        att->set("eff_jing",(int)ob->query("max_jing"));
        att->set("neili",(int)ob->query("max_neili") );
        att->set("max_neili",(int)ob->query("max_neili") );
        att->set("jingli",(int)ob->query("jingli"));
        att->set("eff_jingli",(int)ob->query("eff_jingli"));
        att->set("combat_exp", exp*2/3);
        skills = att->query_skills();
        if (mapp(skills)){
             sk = keys(skills);
             for (i=0;i<sizeof(sk);i++)
             skills[sk[i]] = lv;
        }
        message_vision(HIR"\nֻ�����ѡ���һ�����죬һ��"+att->name()+"���Ŷ��룬��$N�������ҵĹ�����\n\n"NOR,ob);
        att->move(environment(ob));
        att->kill_ob(ob);
        att->add_busy(3);
        return 1;
}

int give_reward(object ob)
{
        int p,e;
        object me,here;

        if (!ob) return 1;
        me = present("yu daiyan",  environment(ob));
        here=environment(ob);
	e = 100 + random(50)+ random(ob->query("combat_exp"))/10000;	
	ob->delete_temp("apply/short");
	if(!ob->query_temp("wd_job1")) return 1;
	if(ob->query_condition("wd_job")||  //add by caiji@SJ
           ob->query_conditon("job_busy")) return 1;// add by caiji@SJ
	else if((string)here->query("short") != "������"){
		ob->delete_temp("wd_job1");
		ob->delete_temp("guard");
		tell_object(ob,CYN"����ʱ���ѵ�������������ְ�أ�����ʧ���ˣ�\n"NOR);
		return 1;
        }
	else if(!present("yu daiyan",  environment(ob)) 
	      && here->query("short") == "������")
		tell_object(ob,CYN"�㿴��ͭ������˳����ɣ�\n"NOR);
	else {    
		message_vision(CYN"�����˵�����ã�ʱ�䵽�ˣ�"+ob->name()+"������ȥ��Ϣ�ɣ�\n"NOR,ob);
		me->add("guard_count",-1);
		if (me->query("guard_count") < 0) me->set("guard_count",0);
	}
	
	e = ob->add_exp_combat(e,"�����","����ͭ��");
	//ob->add("combat_exp",e);
	//ob->add("job_time/����ͭ��",1);
	//GIFT_D->check_count(ob,"�����","����ͭ��");
	p = e/5 + random(e/10);
		
	ob->add("potential",p);
	ob->delete_temp("wd_job1");
	ob->delete_temp("guard");
	if ( (int)ob->query("potential", 1) > (int)ob->query("max_pot", 1))
		ob->set("potential" , ob->query("max_pot", 1));
	tell_object(ob, GRN"��˴ο��ع��õ�"+CHINESE_D->chinese_number(e)+"�㾭�飬"+CHINESE_D->chinese_number(p)+"��Ǳ�ܣ�\n"NOR);
	log_file("job/kanshou",sprintf("%8s%-10s����ͭ�������%3d�㾭�飬%2d��Ǳ�ܣ��־��飺%d��\n",
		ob->name(),"("+ob->query("id")+")",e,p, ob->query("combat_exp")), ob);
	remove_call_out("do_attack");
	ob->apply_condition("job_busy",3+random(3));
	ob->apply_condition("wd_job",6);
	ob->add("job_time/�䵱",1);	
	return 1;
}

int do_yan(string arg)
{
	object me;
	me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ���أ�\n");
        if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");
	if ( arg != "yao" ) 
		return notify_fail("����Ҫ��ʲô��ĥϸ��\n");

	if (!me->query_temp("yao_get"))
		return notify_fail("������û����Ҫ��ĥ��ҩ�ģ���\n");

	if (me->query_temp("yanyao_ok"))
		return notify_fail("���Ѿ���ҩ����ĥ���ˣ���\n");  

	message_vision("$N��ҩ����һ������ҩ�����棬ϸϸ����ĥ������\n", me);
	me->add_busy(2);
	me->delete_temp("yao_get");
	me->set_temp("yanyao_ok",1);
	message_vision(HIY"$N��ĥ��ҩ�ģ������վ��������\n"NOR,me);
	return 1;
}

int do_lianyao(string arg)
{
        object me, ob_yd;
        me = this_player();
        ob_yd = present("yao dai",me);

        if (me->is_busy())
		return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");

	if ( arg != "tongding" ) 
		return notify_fail("����ʲô����ҩ��\n");

        if (me->query("jingli",1) < 600)
		return notify_fail("�㾫�������ˣ�����\n");

        if (!me->query_temp("yanyao_ok") || !( present("yao dai", me)))
		return notify_fail("����ҩ֮ǰ������Ҫ�Ȱ�ҩ�����ҩ��ϸ����\n");

        if (me->query_temp("lianyao"))
		return notify_fail("������������ҩ������\n");

        if (!(present("yu daiyan", environment(me))))
		return notify_fail("\n����Ҫ��ҩ��ͻȻ���������ʦ�ֲ�����ߣ�����������������\n");  
	message_vision("\n$N�������֣���������ϸ��ҩ�����ͭ������ͯ������Χ��ȥ��ˮ�ȷ�Э��������\n", me);
	write(HIG"\n�����ͻȻ����˵������¯���������ר����ҩ������ָ�ӵ�ͯЭ���������\n"+
		"["HIY"kan yao"HIG"]����ҩ��ĳ�ɫ����["HIY"yunqi tongding"HIG"]���ӿ���ƣ�һ��¯���࣬\n"+
		"���ǵ�����¯["HIY" qilu tongding "HIG"]֮ʱ��\n"NOR);
	me->add_busy(3);
	me->delete_temp("yanyao_ok");
	me->set_temp("lianyao",1);
	me->apply_condition("lian_time",50+random(20));
	me->set_temp("finish_time",15+random(5));
	destruct(ob_yd);
	return 1;
}

int do_kan(string arg)
{
	object me;
	int i;
	me = this_player();

	if (me->is_busy())
		return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");

	if ( arg != "yao" ) 
		return notify_fail("��Ҫ��ʲô��\n");

	if (!me->query_temp("lianyao"))
		return notify_fail("������ҩ,��ʲô�ÿ��ģ�\n");

	i = me->query_condition("lian_time",1) - me->query_temp("finish_time",1);
	if ( i <= 2 && i >= -2 ){
		write(HIM"¯���࣬��״͸��������ȫ��£����Ϊһ�����ε��裬ҩ�����磬��ҩ�ѳɣ���\n"NOR);
		return 1; 
	}
	if ( 2 < i && i <= 10 ){
		write(HIG"����ת�£�����ҩ��֭Һ���գ���Ϊһ�ֶ�״͸�������ʼ������£��\n"NOR);
		return 1; 
	}
	if ( 10 < i && i <= 25 ){
		write(WHT"���ƽ��ͣ�ҩ������ȫ������Ȫ�����࣡���������ʼ��֭��\n"NOR);
		return 1; 
	}
	if ( i > 25 ){
		write(YEL"¯����𣬶���ҩ�･������Ȫ���ܡ�\n"NOR);
		return 1; 
	}
	if (  i < -2 ){
		write(BLU"�������ͣ�����ī��һ�ţ�ɢ�������󽹳���ҩ���Ѿ������ˣ�����\n"NOR);
		return 1; 
	}
	return 1;
}

int do_yunqi(string arg)
{
	object me;
	int i;
	me = this_player();

        if (me->is_busy())
		return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");

	if (!me->query_temp("lianyao"))
		return notify_fail("������ҩ������ʲô��ѽ��\n");

	if ( arg != "tongding" ) 
		return notify_fail("\n����ϥ������ͻȻ����������ƣ����ǵ��⣬���ܵ��˶��ޱȾ��ȣ���\n");

	if (me->query("neili",1) < 200 )
		return notify_fail("�����������Ѳ���������ˣ�����\n");

	tell_room(environment(me),me->name()+ "��ϥ��������ɫ���ء�\n",({ me }));

	write(HIW"\n����ϥ����������ĳ����ƻ���ͭ����������տ������ע�붦�ڡ�\n"+
		"ͭ��������һ��һ��֮�£���ն��������ת���������������ȵ�����������\n"NOR, me); 

	i = me->query_condition("lian_time",1) - (1+random(2));

	me->add_busy(1);
	me->add("neili",-(60+random(50)));
	me->apply_condition("lian_time",i);
	return 1;
}

int do_qilu(string arg)
{
	object ob, me;
	int i;
	me = this_player();

        if (me->is_busy())
		return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");

	if ( !arg || arg != "tongding" ) 
		return notify_fail("��Ҫ����ʲô��\n");

	if (!me->query_temp("lianyao"))
		return notify_fail("������ҩ������ʲô¯����͵��ѽ��\n");         

	if (!me->query_condition("lian_time")){
		me->delete_temp("lianyao");
		return notify_fail("���ж�̫�����Ѱ����������ˣ���\n");
	}
	if (me->query("neili",1) < 500 )
		return notify_fail("�����������Ѳ��ܰѵ�ҩ�ĳ�ͭ���ˣ�����\n");

	i = me->query_condition("lian_time",1) - me->query_temp("finish_time",1);

	if ( i >= -2 && i <= 2 ) {
		message_vision(YEL"\n$NһԾ�������һ�����𣡡���������ͭ��������һ����һ��ɫ���쵵ĵ���,\n"+
				"�ѡ�࣡���һ��Ӧ������$N΢һ���֣��罫����ӵ����С�\n"NOR, me);
		ob=new(__DIR__"obj/wd_dan");
		ob->set("owner", me->query("id"));
		ob->move(me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");
		return 1; 
	}
	if ( i > 2 && i < 11 ) {
		message_vision(WHT"\n$N������ͭ��������һ�ģ�һ�鶳״�����ͭ���е��˳��������ڵ��ϣ�$N����Ѽ���\n"NOR, me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");
		return 1; 
	}
	if ( i > 10 ){
		message_vision(RED"\n$N������ͭ��������һ�ģ�ͭ���ڵ�ҩˮ��ͷ���Ե����˳�����\n"+
                               "����$N�����ϡ����ϣ���ʹ�ޱȡ�\n"NOR, me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");
		me->receive_damage("qi", me->query("max_qi")/2);
		me->receive_wound("qi", me->query("max_qi") / 2);
		me->unconcious();
		return 1; 
	}
	if ( i < -2 ){
		message_vision(BLU"\n��ͯ�����ְ˽ŵĴ�ͭ���в���һЩ�յĽ��ڵ�ҩ���������ע����ˮ��ϴ��\n"+
                               "$Nһ�����ԣ�����������������\n"NOR, me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");                 
		return 1; 
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	if ( me->query_temp("wd_job1") && dir == "east" )
		return notify_fail("�����ڿ���ͭ���������뿪��\n");

	if (me->query_temp("lianyao") && dir == "east" ){
		me->delete_temp("lianyao");
		me->apply_condition("lian_time",0);
		me->delete_temp("finish_time");
		me->apply_condition("wd_busy",10);
		message_vision(HIY"$N���뵤��������ʧ�ܣ���\n"NOR,me);
	}
	return ::valid_leave(me, dir);
}
