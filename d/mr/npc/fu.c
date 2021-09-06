// /d/mr/npc/murong-fu.c  Ľ�ݸ�
// by leontt /12/05/2000
// by tiantian@sj 6/3/2000 fix mr job bug
// By Spiderii@ty����bishen quest
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
#include "skill.h"
int ask_fuming(string arg);
int ask_bo();
string ask_fenglu();
string ask_sword2();
string ask_skill();
string ask_wang();
string ask_learn();
string ask_dan();
string ask_dan1();
string ask_ge();
string ask_sword();
string ask_book();
string ask_book2();
string ask_times();
string ask_9dan();
int ask_bishen();
int ask_fangqi();

void create()
{
        object weapon;
        set_name("Ľ�ݸ�",({"murong fu","murong","fu"}));
        set("title","����Ľ�ݹ���");
        set("nick","�Ա�֮�� ��ʩ����"); 
        set("long",
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݸ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 27);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("no_get","Ľ�ݸ�����������");

        set("max_qi",2000);
        set("max_jing", 3000);
        set("eff_jingli", 4000);
        set("neili",3500);
        set("max_neili", 5000);
        set("jiali", 1);
        set("combat_exp",1500000);
        set("dan", 10);
        set("shen", -1000);
        set("no_bark",1);
        set("score", 50000);
        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
                (: exert_function, "shenyuan" :),
                (: perform_action, "strike.riyue" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "sword.lianhuan" :),
        }));
        set_skill("strike",170);
        set_skill("finger",170); 
        set_skill("dodge",180);
        set_skill("force", 170);
        set_skill("canhe-zhi", 160);
        set_skill("murong-jianfa",170);
        set_skill("shenyuan-gong", 180);
        set_skill("yanling-shenfa", 160);
        set_skill("xingyi-zhang",170);
        set_skill("douzhuan-xingyi", 180);
        set_skill("parry", 180);
        set_skill("sword", 270);
        set_skill("literate", 170);
        set_skill("murong-daofa", 160);
        set_skill("blade",160);
        set_skill("xingyi-jianzhen",170);

        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "yanling-shenfa");
        map_skill("strike", "xingyi-zhang");
        map_skill("parry", "murong-jianfa");
        map_skill("sword", "murong-jianfa");
 
        prepare_skill("finger","canhe-zhi");
        prepare_skill("strike","xingyi-zhang");

        create_family("����Ľ��",2,"����");

        set("inquiry", ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݸ���\n",
                        "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
                        "rumors" : "�Ҹ�ͻȾ�񼲣����������˼����һ�涼û���������¶������Σ�\n",
                        "����" : "�ҵĹ���ס����٢��ɽׯ���������������µ������񶴡�\n",
                        "��ʩˮ��" : (: ask_ge :),
                        "Ľ�ݲ�" : (: ask_bo :),
                        "����" : (: ask_book :),
                        "ٺ»" : (: ask_fenglu :),
                        "������" : (: ask_wang :),
                        "����" : (: ask_sword2 :),
                        "����" : (: ask_sword :),
                        "����" : (: ask_times :),
                        "��ת����"  : (: ask_skill :),
                        "��¶����ɢ" : (: ask_dan1 :),
                        "ͼ��" : (: ask_book2 :),
                        "��ѧ" : (: ask_learn :),
                        "����" : (: ask_fuming :), 
                        "����" : (: ask_fangqi :),
                        "�Ա�֮����ʩ����" : (: ask_bishen :),

        ]));
        set("dan_count", 2);
        set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 2);
        setup();
        if (clonep()) {
                weapon = unew(BINGQI_D("sword/biyu-jian"));
                if (!weapon) weapon = unew(BINGQI_D("changjian"));
                weapon->move(this_object());
                weapon->wield();
                carry_object(__DIR__"obj/cloth3")->wear();
        }
        add_money("gold", 5);
}
void init()
{
        ::init();
        add_action("do_jiaoliang", "jiaoliang");
}
void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 120) {
                command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��"); 
               command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

        if (ob->query_skill("shenyuan-gong", 1) < 100) {
                command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
               command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

       command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
       command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
       command("chat* ����˵��������������һ���ģ������˸�ָ�տɴ�����");
       command("chat* haha");
       command("recruit " + ob->query("id"));
       ob->set("title","����Ľ�ݵ���������");
}

string ask_fenglu() 
{
        object ob=this_player();
        mapping fam = ob->query("family");
        int gold;       
        if ( !fam || fam["family_name"] != "����Ľ��")
           return "��λ"+ RANK_D->query_respect(ob) +"������Ľ�ݼҳ����˻��Ӻ�˵��";
        if ( fam["master_name"] == "����ͬ")
           return "��λ"+ RANK_D->query_respect(ob) +"����Ľ�����ҵ����̫�ͣ����ڻ�û���ʸ���ȡٺ»��";
        if ( fam["master_name"] == "�粨��")
           return "��λ"+ RANK_D->query_respect(ob) +"����Ľ�����ҵ����̫�ͣ����ڻ�û���ʸ���ȡٺ»��";
        if ( fam["master_name"] == "��ұǬ")
           return "��λ"+ RANK_D->query_respect(ob) +"����Ľ�����ҵ����̫�ͣ����ڻ�û���ʸ���ȡٺ»��";
        if ( fam["master_name"] == "�˰ٴ�")
           return "��λ"+ RANK_D->query_respect(ob) +"����Ľ�����ҵ����̫�ͣ����ڻ�û���ʸ���ȡٺ»��";
        if (ob->query("fenglu") && ob->query("fenglu") >= ob->query("age"))
           return "��λ"+RANK_D->query_respect(ob) +"�����Ѿ����ٺ»�ˣ����ǵ����������ɡ�";        
         ob->set("fenglu",ob->query("age"));         
         command ("addoil " + ob->query("id"));         
         message_vision(NOR"Ľ�ݸ�����$NһЩ"HIY"�ƽ�"NOR"��\n"NOR,ob);
         gold=(int)(ob->query_skill("shenyuan-gong",1)*30000);
         MONEY_D->pay_player(ob, gold);
         return "������������ٺ»����Ը��λ"+ RANK_D->query_respect(ob) +"��Ҫʹ��ʧ�����úøɰɣ�";         
}

string ask_sword2()
{
        object me=this_player() , weapon;
        mapping fam;

        if (!(fam = me->query("family")) || fam["family_name"] != "����Ľ��")
           return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";
        weapon = present("biyu jian", this_object());
        if(!objectp(weapon))    weapon = unew(BINGQI_D("sword/biyu-jian"));
        if(!objectp(weapon))
                return "�����Ѿ�����������, ���ڲ��������";  
        command("unwield biyu jian");
        weapon->move(me);
        command("wield jian");
        message_vision("\n$N����$nһ�ѱ��񽣡�\n", this_object(), me);
}

string ask_wang()
{
	mapping fam;
	if (!fam = this_player()->query("family") || fam["family_name"] !="����Ľ��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "�������ұ��ã�һֱ������ܵĺ��ϣ����Ҷ��ܳ�ʱ��û�м������ˡ�\n";
}

string ask_skill()
{
	mapping fam;
	if (!(fam = this_player()->query("family"))|| fam["family_name"] != "����Ľ��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "��ת��������Ľ�ݼҵľ�ѧ������ע���мܺ�����\n";

}

string ask_ge()
{
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��"; 
	return "��ʩˮ������Ľ���ղ������ؼ�֮���ڣ����ҵ���.....\n";
}

string ask_sword()
{
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "��������ү�����ź��������ð�������������úñ��ܣ�\n";
}

string ask_book()
{
        object ob;
        mapping fam;
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (!(fam = this_player()->query("family")) || fam["master_name"] != "Ľ�ݸ�")
        return RANK_D->query_respect(this_player()) +
                "��������������̸������";

        if (  present("douzhuan xingyi", this_player()) ) 
                return RANK_D->query_respect(this_player()) +
                "���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

        if (query("book_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

        ob = new("/d/mr/obj/shu1");
        ob->move(this_player());

        add("book_count", -1);

        message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
        return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";
}

string ask_book2()
{
        object ob;
        mapping fam;
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (!(fam = this_player()->query("family")) || fam["master_name"] != "Ľ�ݸ�") 
        return RANK_D->query_respect(this_player()) +
                "��������������̸������";
        if ( (int)this_player()->query_skill("douzhuan-xingyi",1)<50)
             return RANK_D->query_respect(this_player()) +
                "��������������̸����ȡͼ�⣿";
        if (  present("douzhuan xingyi", this_player()) )
                return RANK_D->query_respect(this_player()) +
                "���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

        if (query("book2_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

        ob = new("/d/mr/obj/shu2");
        ob->move(this_player());

        add("book2_count", -1);

        message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
        return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}

int ask_bo()
{
        mapping fam;
        if ((int)this_player()->query_temp("marks/ʧ��")) {
                say("Ľ�ݸ����з����������⣬ֱ��" + this_player()->name() + "һ��һ��˵�����Ѿ��������ˣ������ỹ\n"
		"����ȥ����������!\n");
                return 1;
        }
        if (!(fam =this_player()->query("family")) || fam["family_name"] != "����Ľ��"){
        	say("���뱾��������������֪�˻��Ӻ�̸��\n");
	        return 1;
        }
        if ((int)this_player()->query_temp("marks/bai_bo")) {
        	say("���Ѿ��ǼҸ��ĵ����ˣ�����������ѧ��!\n");
        	return 1;
        }
        else {
        	say("Ľ�ݸ����з����������⣬ֱ��" + this_player()->name() + "һ��һ��˵�����Ҹ����������֣�����\n" 
		"�����Ի������书δ�ɣ���ò�Ҫȥ��ȥ���裬����������ģ��ͺ��ҽ���һ�¡�(jiaoliang)\n" );
	        this_player()->set_temp("marks/jiao", 1);
        	return 1;
        }
}

int do_jiaoliang()
{
        object me, obj, jiaxin;
        int current_qi;
	int i;
        me = this_object();
        obj = this_player();
        current_qi = (int)me->query("qi");

        say(obj->name() + "��Ľ�ݸ�˵���ðɣ��Ǿ���ʦ��ָ�㼸�� ��\n");
        set("max_qi", 3500);
        set("jiali", 10);
        set("neili", 3500);
        set("max_neili", 3500);
        set("max_jing", 2000);
	i=10;
        if( obj->query_temp("marks/jiao") ) { 
                obj->set_temp("marks/jiao", 0);
                while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 30) {
                        if ( !present(obj, environment()) )
                                return 1;
		i--;
                        COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"));
               if (((int)me->query("qi")*100/current_qi)< 30|| i==0) {
                                say("Ľ�ݸ���" + obj->name() + "˵���� ������Ľ�������ֳ����ģ������д����ţ� �����϶���ǰȥ���֣�\n"
				"�������������˼ҡ�ϣ�����ܲ�������������Ľ�����ң��⸴�������\n"
                                );
                                jiaxin = new("/d/mr/obj/jiaxin");
                                jiaxin->move(obj);
                                obj->set_temp("marks/bai_bo", 1);
                                message_vision("$N����$nһ�����\n", me, obj);
                                return 1;
                        }
                        COMBAT_D->do_attack(me, obj);
                }
                say("Ľ�ݸ�����" + obj->name() + "����˵�������书δ�ɣ��ͺø���Զ,\n"
		"�㻹�ǰ�������ȥ��!\n"
                );
                this_player()->set_temp("marks/ʧ��", 1); 
         }
        return 1;
}

string ask_learn()
{
       object *ob;
       int j=random(sizeof(my_skills));
       mapping skill = my_skills[j];
       mapping fam;
       int i;
     
       i = 7+random(5);
       ob = all_inventory(environment(this_player()));
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��") // ������Ľ���ɵ���
               return RANK_D->query_respect(this_player()) +
               "�뱾��������������֪�˻��Ӻ�̸��";
       if ((int)this_player()->query("combat_exp") > 2000000 )
               return "���Ѿ����������˾���������ѧ��Ҫ���ҿɲ��������Ĵ���ˡ�\n";
       if( (int)this_player()->query_skill("parry", 1) < 100 ) // �мܱ�����ڵ���100��
               return RANK_D->query_respect(this_player()) +
               "�ڱ�����ѧ�в����������磬���̸������֮��ѧ��";
       if( (int)this_player()->query_skill("douzhuan-xingyi", 1) < 100 )  // ��ת���Ʊ�����ڵ���100��
               return RANK_D->query_respect(this_player())+"�ڱ�����ѧ�в����������磬���̸������֮��ѧ��";
       if( this_player()->query_condition("mr_job") )
               return RANK_D->query_respect(this_player())+"��û����ҽ�����������ء�";
       if( this_object()->is_fighting())
               return "��ʲô�£�û����������æ������";
       if( (int)this_player()->query_condition("wait_mr_job", 1) > 0)
               return RANK_D->query_respect(this_player())+"�ȵȵȰɣ�������û��ʲô����Ȥ���书��ѧ��";

        if(!skill["skill_name"]){
                        return sprintf("SKILL.H�ļ��ڵ�%d�����ܳ�����֪ͨ��ʦ�޸ġ�\n",j);
        }
        else{              
        	this_player()->set_temp("skill_target", skill["skill_name"]);  // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ���������
        	this_player()->set_temp("skill_id", skill["skill_id"]); // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ�Ӣ������
       		this_player()->set_temp("skill_type", skill["skill_type"]); // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ�Ӣ������
        	this_player()->set_temp("skill_lvl", i); // �˱�Ǳ����˴�͵ѧĿ�꼼������Ҫ�ļ���
        	this_player()->apply_condition("mr_job", 30+random(15)); // ���ô˴��������������ʱ�������;
        
        	command( "whisper "+this_player()->query("id")
                        + " �ҹ���Ľ�ݰ������������书����Ҳ����Ϊ֮��Ľ�ġ�" );
       		command("whisper "+this_player()->query("id") +
                        " �ðɣ�"+"��"+skill["skill_name"]+"��"+"��"+skill["skill_id"]+"���Ҵ����Ѿã����ǰ���ѧ�������Ҵ������͡�");
        	
        	new("/d/mr/obj/paper")->move(this_player());
        	
        	if(random(2))
                        return "�����������Ǻã����Ǻá�";
                else
                        return "���������治��";
        	
        }
}

int ask_fuming(string arg)
{
       object me, ob;
       int bouns,timebouns,My_exp,Target_exp;
       float rate; 
       
       me = this_player();
       ob = this_object();

       if( !arg)
       {
               command("say ��Ҫչʾʲô��");
               return 1;
        }

       if( !me->query_condition("mr_job"))
       {
               command("say ������û������ɣ�");
               return 1; 
       }
      
       if( me->is_busy())
       {
               command("say ����æ���أ���ʲô���������˵��");
               return 1;
        }

       if( me->is_fighting())
       {
               command("say ��������أ���ʲô���������˵��"); 
               return 1;
       }
       
       if(!me->query_temp("job_done"))
       {
       		command("say ��ѧ��ʲô�����ˣ��������һ�����");
                return 1;
       }
       
       if( this_object()->is_fighting())
       {
               command("say ��ʲô�£�û����������æ������");
               return 1;
       }
	
       Target_exp = (int)me->query_temp("master_exp");
       My_exp= (int)me->query("combat_exp");
       
       me->add("mr_job",1);
       bouns = (int)me->query_temp("skill_lvl")*5/2;
        bouns += ( me->query_skill("douzhuan-xingyi",1) + me->query_skill("literate",1) )*5/4;
       bouns = bouns + (int)me->query_skill("douzhuan-xingyi", 1)/2;
       bouns = bouns + (int)me->query("int")*random(me->query("int"));
       timebouns = me->query("mr_job")/10;
       
       rate = to_float(Target_exp)/to_float(My_exp);
       if (rate > 2) rate = 2;
        if (rate < 1) rate = 0.6;
       bouns = bouns*rate;
       bouns = bouns+timebouns;
        
       message_vision(CYN"Ľ�ݸ���ϸ�о��������ֽ���ϵ��书��Ҫ���鲻�Խ���˵������һ��"+me->query_temp("skill_target")+"��\n"NOR, me);
       message_vision(CYN"Ľ�ݸ�������$N��ͷ����$N˵�����������ˣ���ȥ��Ϣ�ɡ�\n"NOR, me);
       me->add("combat_exp", (int)bouns);
       me->improve_skill("douzhuan-xingyi", me->query_int()*2);
       if( ((int)me->query("potential", 1)+bouns) >= (int)me->query("max_pot", 1))
       {
               me->set("potential", (int)me->query("max_pot"));
       }
       if( ((int)me->query("potential", 1)+bouns) < (int)me->query("max_pot", 1))
       {
               me->add("potential", (int)bouns/6);
       }
       write(GRN"������"+(string)(bouns)+"�㾭���"+(string)(bouns/4)+"��Ǳ�ܵĽ���\n"NOR); 
      
       log_file("job/mrjob",
        sprintf("%s %s(%s) touxue %s(%s) on %s, exp=%d��\n",     
                me->query("title"), me->name(1), geteuid(me),
                me->query_temp("skill_target"), me->query_temp("skill_id"), ctime(time()), bouns ));
       
       me->delete_temp("skill_target");
       me->delete_temp("skill_id");
       me->delete_temp("skill_type");
       me->delete_temp("skill_lvl");
       me->delete_temp("job_done");
       
       me->clear_condition("mr_job");
       me->apply_condition("wait_mr_job", random(10)+5);
       
       if(present("paper", me))
       {  
       		destruct(present("paper",me));
       }
       
       return 1;		
        
}

int ask_fangqi()
{
        object me=this_player(),obj;

        if( !me->query_condition("mr_job") )
       {
               command("say ������û������ɣ�");
               return 1; 
       }

        command( "say Ҳ�ã���ô������ȥ��Ϣһ��ɡ�" );
        command( "disapp");
        command( "sigh "+me->query("id"));
        obj=me->query_temp("dizi");
        if( objectp(obj) )
                destruct(obj);
        me->delete_temp("skill_target");
        me->delete_temp("skill_id");
        me->delete_temp("skill_type");
        me->delete_temp("skill_lvl");
        me->delete_temp("job_done");
        
        me->clear_condition("mr_job");
        me->apply_condition("wait_mr_job", random(2)+2);
        me->add("combat_exp",-10-random(10));
                return 1;
}

string ask_times()
{
        object ob;
        ob = this_player();
        if(!ob->query("mr_job"))
        {
         return "���ź���"+ob->name()+"�������û��ΪĽ���������ף�";
        }
        return ""+ob->name()+"�����Ѿ������"+CHINESE_D->chinese_number((int)ob->query("mr_job"))+"��Ľ��͵ѧ����";
}

int ask_bishen()
{
	object ob=this_player();
       mapping fam;
	int i, time;
	i = ob->query("combat_exp") - 1000000;
	i /= 1000000;

	time = time() - ob->query("quest/bishen/time");


      if (!(fam = this_player()->query("family")) || fam["family_name"] !="����Ľ��"){
		command("? " + ob->query("id"));
             command("say ���뱾��������������֪Ϊ���д�һ�ʣ�");
             return 0;
        }
	if (ob->query("quest/bishen/pass")) {
		command("? " + ob->query("id"));
		command("say �㲻���Ѿ��������еİ�������");
		return 1;
	}
	if (ob->query("quest/bishen/fail") >=3 && ob->query("registered") < 3){
		command("hmm");
		command("say ������������,�������������ˣ�");
		return 1;
	}
	if ( ob->query("quest/bishen/time") && time < 86400 ) {
		command("shake");
		command("say �����ʱ��δ��,���Ժ�������");
		return 1;
	}
	if ( ob->query("quest/hubo/fail") >= i ){
		command("shake");
		command("say �ҽ���ʱ��δ��,���Ժ�������");
		return 1;
	}
	if ( ob->query("combat_exp") < 1000000) {
		command("shake "+ ob->query("id"));
		command("say ��λ"+RANK_D->query_respect(ob)+"����书���ڸ���,���ڻ����Ǹ������ʱ��");
		return 1;
	}
	if (random(ob->query("kar")) < 26 || random(ob->query_int(1)) < 30){
	       command("look " + ob->query("id"));
		command("poor");
		command("say �����㻹��δ���������а������ڵ�ʱ��!");
		ob->add("quest/bishen/fail", 1);
		ob->set("quest/bishen/time", time());
		log_file("quest/bishen",
			sprintf("%-18s���Ľ�ݸ�������ת���Ƶľ�������ʧ�ܣ�ʧ��%s�Ρ�\n",
				ob->name(1)+"("+capitalize(getuid(ob))+")",
				chinese_number(ob->query("quest/bishen/fail")) 
			), ob
		);
		return 1;
	}
	command("look " + ob->query("id"));
	command("nod " + ob->query("id"));
	command("say �ð�,�Ҿͽ����еİ��������ɡ�");
       command("chat* ������Ц�����ҹ���Ľ������һ������ת���ƾ�������,�γ����ҵ���ɣ�");
       command("chat* yeah");
	log_file("quest/bishen",
		sprintf("%-18sʧ��%s�κ󣬳ɹ���Ľ�ݸ�������ת���ƾ������ڣ�����%d����%d��\n",
			ob->name(1)+"("+capitalize(getuid(ob))+")",
			chinese_number(ob->query("quest/bishen/fail")), 
			ob->query("kar"), 
			ob->query_int(1)
		), ob
	);
	ob->set("quest/bishen/pass", 1);
	ob->set("quest/bishen/exp", ob->query("combat_exp"));
	return 1;
}

