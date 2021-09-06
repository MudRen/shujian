// NPC: lu.c ³�н�
// Lklv 2001.9.28 update
// By Spiderii@ty srf,tjf������ask job��tj.
#include <job_mul.h>
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_job();
string ask_gift();
int ask_num();

#include "gb_lujob.h"

void create()
{
	set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
	set("title", HIW"ؤ��Ŵ�����"NOR);
	set("nickname", "�ư���ͷ");
	set("gender", "����");
	set("age", 45);
	set("long", "����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");

        set("attitude", "friendly");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);
        set("unique", 1);
        set("no_bark",1);
        set("job_npc",1);
        set("no_get","³�нŶ�����˵̫���ˡ�\n");

        set("qi", 3500);
        set("eff_jingli", 2000);
        set("max_qi", 3500);
        set("jing", 2000);
        set("max_jing", 2000);
        set("eff_jing", 3200);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 60);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 190); // �����ڹ�
        set_skill("huntian-qigong", 190); // ��������
        set_skill("strike",195); // ����ȭ��
        set_skill("xianglong-zhang", 190); // ����ʮ����
        set_skill("dodge", 190); // ��������
        set_skill("xiaoyaoyou", 190); // ��ң��
        set_skill("parry", 190); // �����м�
        set_skill("literate", 100);
        set_skill("stick", 185); // ��������
        set_skill("begging", 160);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("parry","xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

    	set("chat_msg_combat", ({
        	(: perform_action, "strike.xiao" :),
        	(: perform_action, "strike.paiyun" :),
        	(: exert_function, "huntian" :),
        }));

        create_family("ؤ��", 18, "�Ŵ�����");

        set("inquiry", ([
                "����ͼ��" : (:ask_me:),
                "��Ч����" : (:ask_job:),
                "����": (: ask_num :),
             "����": (: ask_gift :),
                "���߹�": "����ƽ�������������������׽�һ��Ľ������߹�����\n",
        ]));
        set("count",1);

        setup();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(__DIR__"obj/gb_budai9")->wear();
}

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
		reincarnate();
}

void init()
{
        object me = this_player();
        int exp,pot,shen;

	::init();
        if( me->query_temp("gb_job2")
         && me->query_temp("gb_job2_finish")>=5 ){
                me->delete_temp("gb_job2");
                me->delete_temp("gb_job2_finish");
                exp = 400 + random(300);
                
                exp = me->add_exp_combat(exp,this_object(),"���ϳ�");
                
                pot = exp/5+random(exp/10);
                shen = exp*3;
                command("thumb "+me->query("id"));
                
                me->add("job_time/��Ч����", 1);                
                write( sprintf(HIW"\n�ã���������ˣ���õ���"
	                 + CHINESE_D->chinese_number( exp )
        	         + "��ʵս���飬"
                	 + CHINESE_D->chinese_number( pot )
           	      	+ "��Ǳ�ܺ�"
               		+ CHINESE_D->chinese_number( shen )
                 	+ "������\n" NOR));
        	
        	me->add( "potential", pot );
        	if( me->query("potential") > me->query("max_pot") )
                	me->set("potential", me->query("max_pot") );
            	me->add( "shen", shen );
		me->set("job_name","���ղ��ϳ�");
		
            	log_file("job/caoliao", sprintf("%8s%-10s���ղ��ϳ����񣬾��飺%3d��Ǳ�ܣ�%3d��Ŀǰ���飺%d��\n",
	           me->query("name"), "("+me->query("id")+")", exp, pot,me->query("combat_exp")),me );
        }
        add_action("qingjiao", "qingjiao");
}

string ask_me()
{
        object me = this_player();

        if ( me->query("family/family_name") != "ؤ��" ){
                command("laugh " + me->query("id"));
                return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
        }
        if (random(4)) {
                command("hehe");
                return "�Ҳ�֪����";
        }
        if (query("count")){
                new(__DIR__"obj/stick-book")->move(me);
                add("count", -1);
                command(":(");
                message_vision("$N��$nһ��ֽƬ��\n", this_object(), me);
                return "�ðɣ��Ȿͼ������ȥ�о��������������ҡ�";
        }
        command("sigh " + me->query("id"));
        return "��������һ����ͼ���Ѿ����������ˡ�";
}

string ask_gift()
{
        object me = this_player();
        mapping fam;

        fam = me->query("family");
        if (!fam || fam["family_name"] !="ؤ��")
           return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��?��\n";
        if( me->query("gb/gift") )
           return RANK_D->query_respect(me)+"����Ҫ���������һ��ֻ��Ҫһ�Ρ�\n";

           me->set("job_time/ץ��",1000);
           me->set("job_time/ؤ��",1000);
           me->set("job_time/��ɱ",1000);
           me->set("job_time/��Ħ��",1000);
           me->set("gb/gift", 1);

        return  "���ˣ���ĸ漱����Ħ�¡���ɱ�������㹻������.\n" ;
}

string ask_job()
{
        object me = this_player();
        int exp = me->query("combat_exp");

        //if( (int)me->query("shen") < 0 )
          //      return "�ҿ����ͷ��Ŀ����������ˣ�����ܷ��İѾ��������и����㡣\n";

        if( exp < 3000 )
                return RANK_D->query_respect(me) + "���д��ģ��κ��书��Ϊ̫�\n";

        if( !wizardp(me) && me->query_condition("job_busy"))
                return "����������û��ʲô������Ȼ������ɡ�\n";

		if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
			    return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

       if ( me->query_condition("killer"))
                 return "�������ǹٸ�׽�õ�Ҫ���������ȴ�������Լ��������!"; // By Spiderii@ty��������
        if( me->query("menggu") )
                return "�ߣ����⺺�飬����Ҫ����\n";

        if( exp < 80000 ){
                return gb_job1();
        }
        else if( exp < 500000 ){
                return gb_job2();
        }
        else if(exp < 1000000 ){
                return gb_job3();
        }
        else {
                return smy_job();
        }
        return "������û��ʲô���Ը������������ˡ�\n";
}

int ask_num()
{
        object me = this_player();
        //old
        //int num = me->query("job_time/��Ч����");
        //old end
        int num = me->query("job_time/�漱") + me->query("job_time/��ɱ") + me->query("job_time/��Ħ��");

        command( "say "
        	+ RANK_D->query_respect(me) + "�Ѿ�Ϊ��������"
        	+ CHINESE_D->chinese_number( num )
        	+ "�ι��ס�" );
        command("addoil " + me->query("id"));
        return 1;
}

int qingjiao(string arg)
{
        object me = this_player();
        int lvl = me->query_skill("stick", 1);

        if (!living(me)) return 0;
        if (arg != "stick" || !present("stick book", me)) return notify_fail("��Ҫ���ʲô��\n");
        if (!living(this_object())) return notify_fail("���Ȱ���Ū����˵�ɣ�\n");
        if (this_object()->is_busy() || this_object()->is_fighting())
        	return notify_fail(this_object()->query("name")+"��æ���ء�\n");
        if (lvl < 30) return notify_fail("��Ļ���������Ϊ��������³�нŵĽ����ƶ��Ƕ���\n");
        if (lvl < 101) {
                write("�����Ű���ͼ����³�н���̡�\n");
                me->receive_damage("jing", 30);
                write("��ġ����������������ˡ�\n");
                me->improve_skill("stick", me->query("int"));
                return 1;
        }
        command("blush " + me->query("id"));
        return notify_fail("");
}
