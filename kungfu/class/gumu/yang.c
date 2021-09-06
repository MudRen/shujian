// yang.c ���
// By River 98.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_sword();
int pfm_haichao();
int pfm_anran();
string ask_skill();
string ask_skill1();
string ask_skill2();
string ask_quest();

void create()
{
	set_name("���",({"yang guo","yang","guo"}));
	set("title",HIW"��Ĺ����"NOR);
	set("nickname",HIY"������"NOR);
	set("long", "�������������µ���������һ�۵����ڲ�ȥһ����Ӣ�ۺ�����\n");
	set("age", 39);
	set("attitude", "friendly");
	set("gender", "����");
	set("shen", 10000);
	set("per", 36);
	set("str", 40);
	set("int", 35);
	set("con", 40);
	set("dex", 35);

        set("max_qi", 10500);
        set("max_jing", 7000);
        set("neili", 18500);
        set("eff_jingli", 7500);
        set("max_neili", 18500);
        set("jiali", 150);
        set("combat_exp", 4800000);
        set("unique", 1);

        set_skill("sword",350);
        set_skill("qimen-bagua",120);
        set_skill("dodge",350);
        set_skill("strike",350);
        set_skill("force", 350);
        set_skill("hand", 350);
        set_skill("cuff", 350);
        set_skill("parry", 350);
        set_skill("yunu-jianfa", 350);
        set_skill("finger",140);
        set_skill("literate", 250);
        set_skill("xiantian-gong", 120);
        set_skill("hamagong",300);
        set_skill("medicine",120);
        set_skill("jingmai-xue", 80);
        set_skill("yunu-shenfa", 350);
        set_skill("xuantie-jianfa", 370);
        set_skill("anran-zhang", 380);
        set_skill("quanzhen-jianfa",360);
        set_skill("tianluo-diwang", 340);
        set_skill("yunu-xinjing",350);
        set_skill("jiuyin-zhengong",160);
        set_skill("meinu-quanfa",220);
        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-zhang");        
        map_skill("hand", "tianluo-diwang");
        map_skill("strike", "anran-zhang");        
        prepare_skill("strike","anran-zhang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function, "xinjing" :),
		(: pfm_haichao :),
		(: perform_action, "strike.xiaohun":),
		(: pfm_anran :),
	}));

	create_family("��Ĺ��",3,"������");

	set_temp("apply/damage", 70);
	set_temp("apply/dodge", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 70);

	if (random(3))
		set("env/��������", "��ӿ");

        set("inquiry", ([
		"��Ĺ" : "���ջ�ɽ����Ӣ�۾��������������ڴ��������꣬�������£�����\n"+
			"�����ڴ˳���һ�����������ӣ�",
		"С��Ů" : "�������Ұ��ޣ�������������",
		"������" : (: ask_sword :),
		"��������" : (: ask_sword :),
                "�书"  : (: ask_skill :),
                "����"  : (: ask_skill1 :),
                "�ڹ�"  : (: ask_skill2 :),
                "��Ĺʯ��"  : (: ask_quest :),

	]));

        setup();
	carry_object(BINGQI_D("sword/gangjian"));
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object("/d/gumu/obj/pao1")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	if(!fam || fam["family_name"] != "��Ĺ��"){
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if(ob->query("gender") != "����") {
		command("bow "+ ob->query("id"));
		command("say �ҿ�ֻ����ͽ����ȥ�������������԰ɡ�");
		return;
	}       
	if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
		command("say �ڹ��ǹ�Ĺ�书֮������"); 
		command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
		return;
	}   
	if((int)ob->query_int() < 32 ) {
		command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say "+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	if((int)ob->query("shen") < 10000){
		command("say �ҹ�Ĺ�������߽����У�һ���������塣");
		command("say ��λ" + RANK_D->query_respect(ob)+"����������ȥ������������º������ɣ�");
		return;
	}
	command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");         
    command("chat ��Ĺ�书���ֽ�����"+ ob->name() +"�ɱ���Ϊʦ�������ˣ�");
        command("chat* pat " + ob->query("id"));
	command("recruit " + ob->query("id"));
	ob->set("title",HIW"��Ĺ��������´���"NOR);
}

string ask_sword()
{
	object ob=this_player();
	mapping fam = ob->query("family");

	if ( !fam || fam["family_name"] != "��Ĺ��")
		return RANK_D->query_respect(ob) +"���ҹ�Ĺ���ˣ���֪���˻�������";

	if ( fam["generation"] != 4 )
		return RANK_D->query_respect(ob) +"����������´��ˣ����ǵ��Ժ���˵�ɡ�";

	if ( ob->query("shen") < -100000)
		return RANK_D->query_respect(ob) +"а��̫�أ���ض���ǰ��Ҳ��Ը���Ľ�������������";

	if ( ob->query("ygpass"))
		return "�Ҳ����Ѿ���������������������֮����ô��";

	if ( ob->query("gender")=="����") {
		command("pat "+ ob->query("id"));
		command("say ���������������ϣ����������������ڶ��´���Ĺǰ��������������");
		ob->set("ygpass", 1);
		return "������Ϣ���������У����ص��������ں�ˮ�������ľ��ϣ���ú�ȥ����һ�°ɡ�";
	}
	if ( ob->query("gender") == "Ů��"){
		if ((int)ob->query_str() < 35 )
			return "��λ"+RANK_D->query_respect(ob) +"������������Ҫ���ߵ��������㻹����Ŭ��һ���ɡ�";
		if ((int)ob->query_dex() < 35 )
			return "��λ"+RANK_D->query_respect(ob) +"���ں�ˮ����ϰ����������Ҫ���ߵ������㻹����Ŭ��һ���ɡ�";
		if ((int)ob->query_skill("sword", 1) < 200 )
			return "��λ"+RANK_D->query_respect(ob) +"�Ļ���������������������������Եֵ���ˮ�ĳ����";
		if ((int)ob->query_int() < 35 )
			return "��λ"+RANK_D->query_respect(ob) +"�����Ի������ߣ������������Ҫ���Ŀھ���";
		command("pat "+ ob->query("id"));
		command("say ���������������ϣ����������������ڶ��´���Ĺǰ��������������");
		ob->set("ygpass", 1);
		return "������Ϣ���������У����ص��������ں�ˮ�������ľ��ϣ���ú�ȥ����һ�°ɡ�";
	}
}

int pfm_haichao()
{
	object me,weapon;
	me = this_object();
	weapon = present("gangjian",me);
	if( me->is_busy()) return 0;
	if( objectp(weapon)){
		set("jiali", 50);
		command("wield jian");
		command("perform haichao");
		if(random(10) > 5){
			set("jiali", 150);
			command("unwield jian");
		}
		return 1;
	}
	else {
		new(BINGQI_D("sword/gangjian"))->move(me);
		set("jiali", 50);
		command("wield jian");
		command("perform haichao");
		if(random(10) > 5){
			set("jiali", 150);
			command("unwield jian");
		}
		return 1;
	}
	return 1;
}

int pfm_anran()
{
	object me,weapon;
	me = this_object();
	weapon = me->query_temp("weapon");

	if(me->is_busy()) return 0;
	if( me->query("eff_qi") < 1 ) return 0;
	if( me->query("max_qi") / me->query("eff_qi") < 2 ) return 0;
	if(objectp(weapon)) weapon->unequip();
	this_object()->set("jiali", 150);
	command("perform anran");
	return 1;
}

string ask_skill()
{
	mapping fam;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��" )
		return "����"+RANK_D->query_respect(this_player())+"���޹ϸ𣬲�֪�˻��Ӻ�̸��";

	if( this_player()->query_temp("gumu_skill") )
		return RANK_D->query_respect(this_player()) + "�������������̡����������ڹ�����������⣡";

	if( this_player()->query_skill("sword") < 150 )
		return RANK_D->query_respect(this_player()) + "�Ľ����ƺ���������������";

	if( this_player()->query("gumu_given") >= 300 )
		return RANK_D->query_respect(this_player()) + "������书�Ѿ������ˣ����Ѿ�ûʲô����ָ�̵��ˡ�";

	if( this_player()->query_skill("yunu-xinjing", 1) > this_player()->query("gumu_given") + 30 ) {
		this_player()->set_temp("gumu_skill", 1);
		return RANK_D->query_respect(this_player()) + "���ڹ����о������Ҿ�ָ���㼸�°ɣ����������ҹ��ڡ�"HIY"����"CYN"����"HIY"�ڹ�"CYN"�������ʣ�";
	} else {
		return "�ҽ��ڲ��Ǹ�ָ�̹�������ѧ�Ĺؼ����Ļ����Լ�Ŭ����ϰ����\n";
	}
}

string ask_skill1()
{
	object me, ob;
	int skill, pot;
	mapping fam;

	me = this_player();
	ob = this_object();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��" )
		return "����"+RANK_D->query_respect(this_player())+"���޹ϸ𣬲�֪�˻��Ӻ�̸��";

	if( this_player()->query_skill("sword") < 150 )
		return RANK_D->query_respect(this_player()) + "�Ľ����ƺ���������������";

	if( !me->query_temp("gumu_skill") )
		return "���������������ϣ����������������ڶ��´���Ĺǰ��������������";

	if( (int)me->query_skill("yunu-xinjing", 1) > 300 ) 
		skill = 300 - (int)me->query("gumu_given");
	else skill = (int)me->query_skill("yunu-xinjing", 1) - (int)me->query("gumu_given");

	pot = skill * 10;
	pot += random(pot/2);

	skill /= 30;
	if( skill < 1 ) skill = 1;

	message_vision(HIB"$n΢Ц��������еĽ�������죬������ᣬ����Ȼ�����������֮�������������š�\n"NOR,me,ob);
	message_vision(HIW"$N����$n��չʾ�ķ�����ϰ����Ȼ�书���г�����\n"NOR,me,ob);

	me->delete_temp("gumu_skill");
	me->set("gumu_given", (int)me->query_skill("yunu-xinjing", 1));

	me->set_skill("xuantie-jianfa", me->query_skill("xuantie-jianfa", 1) + skill );
	me->set_skill("quanzhen-jianfa", me->query_skill("quanzhen-jianfa", 1) + skill );
	me->set_skill("yunu-jianfa", me->query_skill("yunu-jianfa", 1) + skill );
	me->set_skill("sword", me->query_skill("sword", 1) + skill );
	me->add("potential", pot );

	tell_object(me, HIC"��ġ����������������ˣ�\n"NOR);
	tell_object(me, HIC"��ġ�ȫ�潣���������ˣ�\n"NOR);
	tell_object(me, HIC"��ġ���Ů���Ľ��������ˣ�\n"NOR);
	tell_object(me, WHT"���������" + chinese_number(pot) + "��Ǳ�ܡ�\n"NOR);

	return RANK_D->query_respect(me) + "���ʹ��ˣ����Ǹ�����֮�Ű�����������";
}

string ask_skill2()
{
	mapping fam;
	object me, ob;
	int skill, neili;

	me = this_player();
	ob = this_object();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��" )
		return "����"+RANK_D->query_respect(this_player())+"���޹ϸ𣬲�֪�˻��Ӻ�̸��";

	if( this_player()->query_skill("sword") < 150 )
		return RANK_D->query_respect(this_player()) + "�Ľ����ƺ���������������";

	if( !me->query_temp("gumu_skill") )
		return "������Ϣ���������У����ص��������ں�ˮ�������ľ��ϣ���ú�ȥ����һ�°ɡ�";

	if( (int)me->query_skill("yunu-xinjing", 1) > 300 ) 
		skill = 300 - (int)me->query("gumu_given");
	else skill = (int)me->query_skill("yunu-xinjing", 1) - (int)me->query("gumu_given");

	neili = skill/2;
	neili += random(neili/4);

	skill = random(skill)/30;
	if( skill < 1 ) skill = 1;

	message_vision(HBYEL"$n������Ϣ���������У����ص�����������ۼ�������������Ů�ľ���\n"NOR,me,ob);
	message_vision(HIW"$N����$n�������������Ŷ�ʱ�⿪�����ڹ��������ָ�����һ�㡣\n"NOR,me,ob);

	me->delete_temp("gumu_skill");
	me->set("gumu_given", (int)me->query_skill("yunu-xinjing", 1));

	me->set_skill("yunu-xinjing", me->query_skill("yunu-xinjing", 1) + skill );
	me->set_skill("force", me->query_skill("force", 1) + skill );
	tell_object(me, HIC"��ġ���Ů�ľ��������ˣ�\n"NOR);
	tell_object(me, HIC"��ġ������ڹ��������ˣ�\n"NOR);

	me->add("max_neili", neili );
	tell_object(me, WHT"���������Ϊ������" + chinese_number(neili) + "�㡣\n"NOR);

	return RANK_D->query_respect(me) + "���ʹ��ˣ����Ǹ�����֮�Ű�����������";
}


string ask_quest()
{
	mapping fam;
	object me, ob;
	int i, time;

	me = this_player();
	ob = this_object();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��" )
		return "����"+RANK_D->query_respect(this_player())+"���޹ϸ𣬲�֪�˻��Ӻ�̸��";

   i = me->query("combat_exp") - 1000000;
   i /= 100000;

  time = time() - me->query("quest/gmsuper/time");

   if (me->query("quest/gmsuper/pass") || me->query_temp("quest/gmsuper/ask") ) {
            command("? " + me->query("id"));
	return "�Ҳ����Ѿ�����"+RANK_D->query_respect(this_player())+"���ˣ�";
 
    }

   if ( me->query("quest/gmsuper/time") && time < 86400 ) {
            command("shake " + me->query("id"));
        return HIG"���"+CHINESE_D->chinese_time(86400-time)+"�������ʰɡ�";

    }


        if ( me->query("quest/gmsuper/fail") >= i && !me->query("cw_exp"))
                return "�ҹ�Ĺ�似��Ϥ����ʯ��֮�ڣ�" + RANK_D->query_respect(this_player()) + "�书������������������������1��";   

	if( this_player()->query_skill("yunu-xinjing",1) < 550 )
		return "�ҹ�Ĺ�似��Ϥ����ʯ��֮�ڣ�" + RANK_D->query_respect(this_player()) + "�书������������������������2��";


	if( this_player()->query_skill("xuantie-jianfa",1) < 550 )
		return "�ҹ�Ĺ�似��Ϥ����ʯ��֮�ڣ�" + RANK_D->query_respect(this_player()) + "�书������������������������3��";

	if( this_player()->query_skill("yunu-jianfa",1) < 550 )
		return "�ҹ�Ĺ�似��Ϥ����ʯ��֮�ڣ�" + RANK_D->query_respect(this_player()) + "�书������������������������4��";

	if( this_player()->query("relife/gifts/total") < 5 )
		return "�ҹ�Ĺ�似��Ϥ����ʯ��֮�ڣ�" + RANK_D->query_respect(this_player()) + "�书������������������������5��";


   message_vision(HIM"�������$N���˰��죬̾��һ��������ҡҡͷ������һ�ι�Ĺ��������\n"NOR+
                           HIG"ԭ��������������֪�ֳ�Ӣ�ڻ�����Ĺ��������������ʹʵ�����ѣ����Ǵ��ܵ���Ĺ��ƾ���Լ���λ�������¡�\n"+ 
                                "Ѳ�ӹ�Ĺʱ�������ֳ�Ӣ�����Լ������Ļ����ּ�������ʯ�������书��������Ů�ľ������书��΢���\n"+
                                "��һʱ��ʤ���㽫���𽭺��ġ������澭��Ҫּ����ȫĹ�����صĵ���ʯ���Ҷ����������ˡ�����һ������\n"+
                                "�����ˡ��Ŀ��֡����������С��Ů����Ī�����ȣ�ȴ������䷢�������������ܡ� \n"NOR, me);
                command("sneer ");     
                command("say �����������Ƴ���Ů�ľ�֮�������ǲ��ա������澭�����أ���֪�ҹ�Ĺ��Ů�ľ��ο������澭���ϲ�¥����������ô�����Ƶá� ");         
                command("say ���ѽ�����ùñ�����ѧ���������������ſ�֮�ԣ���Ĺ��ȫ����ǿ������һ����֪������");
                command("say �ýк��˵�֪�����Ĺʼ���������������ʦ���ŵġ�");


me->set_temp("quest/gmsuper/ask",1);
me->set("quest/gmsuper/time",time());
	return RANK_D->query_respect(me) + "���ʹ��ˣ��ҹ�Ĺ��ѧ�����󣬾�ȫ�����ˣ���������";

/*
�������ز���
if( random(15)==1 && random(me->query("kar")) > 28 && me->query("id")=="master")
{
    me->set("quest/gmsuper/pass",1);
  message_vision(HIM"�������$N���˰��죬̾��һ��������ҡҡͷ������һ�ι�Ĺ�������ܡ� \n"NOR, me);
    log_file("quest/gmsuper",
            sprintf("%-18sʧ��%s�κ󣬳ɹ���������õ�ʯ�������ݣ�����%d��\n",
                    me->name(1)+"("+capitalize(getuid(me))+")",
                    chinese_number(me->query("quest/gmsuper/fail")), 
                    me->query("kar"), 
            ), me    );
	return "���������������Ц�˼�����";
}

else 
                me->add("quest/gmsuper/fail", 1);
	return "���������������Ц�˼�����";

*/
}
