// yuelao.c ��������

inherit NPC;

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
        set_name("��������", ({ "yuexia laoren", "yuelao", "laoren" }));
        set("long", 
                "�����Ǵ�˵��ר�����ϵ�����Ե�����������ˡ�\n"
                "��������⣬��ü�԰ף��������Ѳ�֪�ж������ˡ�\n"
                "���������Ƕ�����һ���飬�������һ����������������������Щʲô��\n");
        set("gender", "����");
        set("age", 3000);
        set("attitude", "friendly");
        set("str", 500);
        set("int", 500);
        set("con", 300);
        set("per", 325);
        set("no_quest", 1);

        set("max_qi", 10000);
        set("max_jing", 10000);
        set("combat_exp", 20000000);

        set_skill("force", 500);
        set_skill("dodge", 800);
        set_skill("unarmed", 500);
        set_skill("parry", 800);
        set_skill("literate", 900);

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        add_action("do_register", "register");
        add_action("do_register", "jiehun");
        add_action("do_divorce", "divorce");
        add_action("do_divorce", "lihun");
        add_action("do_zuomei", "zuomei");
}

int do_register()
{
        object me, who, meiren;
        int wiz;
        me=this_player();

	message_vision("$N���������$n��ǰһվ��\n", me, this_object());
        if (!me->query_temp("marry")) {
        	command("? "+ me->query("id"));
                command("say �ף�������Ե����û���������ѽ ... ..."); 
                command("say ���������Ȼ�ȥ�����Ҹ����ҵ�������Ե�����ɡ�");
                return 1;
        }
        if (me->query("gender")=="Ů��") {
        	command("pat "+ me->query("id"));
                command("say �ţ������δ�����ǰ����");
                return 1;
        }
        if (!objectp(who=present(me->query_temp("marry"),environment(me)))) {
        	command("? "+ me->query("id"));
                command("say �ţ������Ե�����ˣ�����Ϊʲô���δ����ûһ������");
                command("say ������δ���޵����������Ҳ���Ϊ������ɵǼ�������");
                return 1;
        }
        if (who->query_temp("marry")!=me) {
        	command("? "+ me->query("id"));
                command("say �����������δ����Ϊ���ִ�Ӧ��������ˣ�����");
                command("say �����뿪ʲô��Ц�������������������");
                return 1;
        }
        wiz = wizardp(me)||wizardp(who);
        if (!wiz && !who->query_temp("meiren")) {
        	command("say "+wiz);
        	command("pat "+ me->query("id"));
                command("say ����Ե��׻�˵�ĺá���ĸ֮����ý��֮�ԡ�������̶���޸�ĸ����Ҳ���ˡ�");
                command("say ������ý��֮�ԣ���Ҳ̫�����ˡ�");
                command("say ����ȥ�Ҹ�ý�����ɣ������ڴ���֤���Ҳ���Ϊ�������顣");
                return 1;
        }
        if (!wiz && !objectp(meiren=present(who->query_temp("meiren"),environment(me)))) {
        	command("pat " + me->query("id"));
                command("say �ţ�����˶�������ˣ�������ý�������Ķ�ȥ����");
                command("say ���ý���ҵ���������Ҳ���Ϊ������ɵǼ�������");
                return 1;
        }        
	if(wiz && sizeof(filter_array(all_inventory(environment(me)) - ({ me,who }), (: interactive :))) ){
		tell_object(who,"�����ȵȵȰ� ������ղ�����\n");
		tell_object(me,"�����ȵȵȰ� ������ղ�����\n");
		return 1;
	}
        command("say �����������ü��ˣ�һ���뱸�������Ϊ���ǵǼǣ�");
        message_vision("�������˵�ͷ����Ե�����˷���д��Щʲô��\n", me);
        command("say ��ϲ����ϲ��");
        if(wiz) command("say ��ף��λ��ͷ���ϣ��������ӡ�");
        else {
        	command("chat ����������������");
        	command("chat "+me->name()+"��"+who->name()+"��"+meiren->name()+"��ý������ϲ����Ե����λ����������֤��");
        	command("chat ��ף��λ��ͷ���ϣ��������ӡ�");
        }
                
	who->delete_temp("marry");
        who->delete_temp("meiren");
        who->set("marry/id",me->query("id"));
	who->set("marry/name",me->query("name"));
        me->delete_temp("marry");
        me->set("marry/id",who->query("id"));
	me->set("marry/name",who->query("name"));
	me->set_temp("marrying",1);
	me->set_temp("bride", who->query("id"));
	who->set_temp("groom", me->query("id"));
	new("/clone/misc/marry-token")->move(me);
	new("/clone/misc/marry-token")->move(who);
	me->save();
	who->save();
	message_vision("$N��$n�����˶������\n", me, who);
        return 1;
}

int do_zuomei(string arg)
{
        object me, who;
        me=this_player();
        
	if (me->query("age") < 18) {
		write("�㻹С��û���ʸ���ý��\n");
		return 1;
	}
        if (!arg || !objectp(who=present(arg,environment(me)))) {
                write("��Ҫ��˭��ý��\n");
                return 1;
        }
	if (me==who || me==who->query_temp("marry")) {
		write("�Լ����Լ���ý����̫�ðɣ�\n");
		return 1;
	}
        if (who->query("gender")!="Ů��") {
                write("�ţ���ý��ΪŮ����ý��\n");
                return 1;
        }
        if (!who->query_temp("marry")) {
                write("�ţ�����û�����鰡����Ϲ��ʲô�壿����\n");
                return 1;
        }
	if (who->query_temp("meiren")) {
		write("�Ѿ�����Ϊ����ý�ˡ�\n");
		return 1;
	}
	message_vision("$N���Ц�ݣ�����������һ��ȭ�������Ǹ������ӣ�\n", me);
        command("say "+RANK_D->query_respect(me)+"Ը���"+who->name(1)+"��ý��");
        command("say ����ǳ���֮�������°����ü��ˣ�����ͼ�������");
        who->set_temp("meiren", me);
        return 1;
}

int do_divorce(string arg)
{
        object me,who;
        int wiz;
        me=this_player();
        if (!arg) {
                write("������˭��飿\n");
                return 1;
        }
                
        if (!me->query("marry")) {
                command("say �����û����飡");
                return 1; 
	}
        if (me->query("gender")=="����") {
                if (me->query("marry/id") != arg) {
                	command("? "+ me->query("id"));
                        command("say ���˸������������ӣ�");
                        return 1; 
		}
                if (!who=find_player(arg)) {
                	command("pat "+ me->query("id"));
                        command("say �Բ������������ڲ������ϣ����ܰ����������");
                        return 1; 
		}
                if (!me->query_temp("divorcing")) {
                	command("ah "+ me->query("id"));
			command("say �����㵱���������������������ǣ�������������һ�Ρ�");
                        me->set_temp("divorcing",1);
                        return 1; 
		}
		me->delete_temp("divorcing");
                me->delete("marry");
		me->add("divorce", 1);
                who->delete("marry");
                tell_object(who, me->name(1)+"�������ˡ�\n");
        }
        else {
                if (me->query("marry/id") != arg) {
                	command("? "+ me->query("id"));
                        command("say ���˸����������ɷ�");
                        return 1; 
		}
                if (!who=find_player(arg)) {
                	command("pat "+ me->query("id"));
                        command("say �Բ������ɷ����ڲ������ϣ����ܰ����������");
                        return 1; 
		}
                if (!me->query_temp("divorcing")) {
                	command("ah "+ me->query("id"));
			command("say �����㵱������������ɷ�������ǣ�������������һ�Ρ�");
                        me->set_temp("divorcing",1);
                        return 1; 
		}
		me->delete_temp("divorcing");
                me->delete("marry");
		me->add("divorce", 1);
                who->delete("marry");
                tell_object(who, me->name(1)+"�������㣬��֪�Ǹ�˭˽��ȥ�ˡ�\n");
	}
	wiz = wizardp(me)||wizardp(who);
        command("say �� ... ...");
        if(!wiz){
        	command("chat �ӽ�����"+me->name(1)+"��"+who->name(1)+"�Ͳ����Ƿ����ˡ�");
        	command("chat ��һ׮ʧ�ܵĻ������� ... ... ");
        }
	if (present("yu pei", me)) present("yu pei", me)->lost(me);
	if (present("xiang nang", me)) present("xiang nang", me)->lost(me);
	if (present("yu pei", who)) present("yu pei", who)->lost(who);
	if (present("xiang nang", who)) present("xiang nang", who)->lost(who);
        return 1;
}
