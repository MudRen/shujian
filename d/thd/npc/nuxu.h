int ask_marry()
{
        object nvxu, user;
        
object ob = this_player();
        string id;
        int user_load = 0, user_exist = 1;

        if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
                command("sneer " + ob->query("id"));
                command("say ��Ҳ��Ȣ���ţ��±��Ӱɣ�");
                return 1;
        }
        if (ob->query("gender") == "Ů��") {
                command("say �㵱��Ů����ͬ�������������");
                return 1;
        }
        if (ob->query("class") == "bonze") {
                command("sneer " + ob->query("id"));
                command("say ����Ҳ���˷��ģ���Ȣ���ţ��Ȼ�����˵�ɣ�");
                return 1;
        }
        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id) {
                if (id == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
                        say(CYN"��ҩʦЦ����" + RANK_D->query_rude(ob) + "�����������������\n"NOR);
                        return 1;
                }
                if (!(user = find_player(id))) {
                        user = new(LOADUSER_OB, id);
                        user->set_name("", ({ id }));
                        if (!user->restore()) {
                                destruct(user);
                                user_exist = 0;
                        }
                        else user_load = 1;
                }
                if (user_exist && nvxu->query("death_count") == user->query("death_count")) {
                        command("say СŮ�Ѿ������" + nvxu->query("name") + "�ˡ�");
                        if (user_load) destruct(user);
                        return 1;
                }
                if (user_load) destruct(user);
        }
        if (ob->query("marry")) {
                command("sneer " + ob->query("id"));
                command("say �㲻���Ѿ�Ȣ��������������޸��ı��ҵ��ˣ��������£��ݹ��Ϸ�����");
                return 1;
        }
        if ((int)ob->query("shen") <= -200000) {
                command("say ����ƽ�����������ˣ����������޶�����аħ���������һ���ߣ�");
                return 1;
        }
        if ((int)ob->query("shen") >= 200000) {
                command("say ����ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ���ߣ�");
                return 1;
        }
        if (ob->query("age") > 49) {
                command("sneer " + ob->query("id"));
                command("say ����ô������ͷҲ������Ů�����ɴ�������Ů�����ˡ�\n");
                return 1;
        }
        if (ob->query("age") < 20) {
                command("say �㻹С���ȳ����������ɡ�\n");
                command("pat " + ob->query("id"));
                return 1;
        }
        command("say �ðɣ�������Ҫ���������⿼���㡣");
        command("say ��һ�����书���ڶ��������ɣ���������Ĭд��");
        command("say �������󶼲�������У�");
        command("say Ҫ��׼�����˾�������һ�ذɣ�");
        ob->set_temp("thd_marry", 1);
        return 1;
}

int ask_test1()
{
        object ob=this_player();
        object me=this_object();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") > 1) {
                command("say �Ѿ�������ػ�������ʲô��");
                return 1; 
        }
        
        me->set("combat_exp", 250000);
        me->set("jiali", 25);
        if (present("biyu xiao",me))
                command("unwield xiao");
        me->prepare_skill("strike");
        me->prepare_skill("leg");
        me->prepare_skill("hand");
        me->prepare_skill("finger");
        me->prepare_skill("sword");
        me->reset_action();
        me->prepare_skill("strike", "luoying-zhang");
        say("\n��ҩʦ�ȵ�����һ������Ӣ���ƣ�С�Ľ����ˣ�\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("biyu xiao",me))
                carry_object("/clone/weapon/biyuxiao.c")->wield();
        else
                command("wield xiao");
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                if (!present("biyu xiao",me))
                        carry_object("/clone/weapon/biyuxiao.c")->wield();
                else
                        command("wield xiao");
                me->prepare_skill("finger");
                me->reset_action();
                me->prepare_skill("strike", "luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                me->set("combat_exp", 2000000);
                me->set("jiali", 100);
                return 1;
        }
        me->prepare_skill("strike");
        me->reset_action();
        me->prepare_skill("strike", "luoying-zhang");
        say("\n��ҩʦ�ȵ����ڶ��������｣����С�Ľ����ˣ�\n");
        if (!present("biyu xiao",me))
                carry_object("/clone/weapon/biyuxiao.c")->wield();
        else
                command("wield xiao");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                if (!present("biyu xiao",me))
                        carry_object("/clone/weapon/biyuxiao.c")->wield();
                else
                        command("wield xiao");
                me->prepare_skill("finger");
                me->reset_action();
                me->prepare_skill("strike", "luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                me->set("combat_exp", 2000000);
                me->set("jiali", 100);
                return 1;
        }
        if (present("biyu xiao",me))
                command("unwield xiao");
        me->prepare_skill("strike");
        me->reset_action();
        me->prepare_skill("hand", "lanhua-shou");
        say("\n��ҩʦ�ȵ�����������������Ѩ�֣�С�Ľ����ˣ�\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                if (!present("biyu xiao",me))
                        carry_object("/clone/weapon/biyuxiao.c")->wield();
                else
                        command("wield xiao");
                me->prepare_skill("finger");
                me->reset_action();
                me->prepare_skill("strike", "luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                me->set("combat_exp", 2000000);
                me->set("jiali", 100);
                return 1;
        }
        me->prepare_skill("hand");
        me->reset_action();
        me->prepare_skill("finger", "tanzhi-shentong");
        say("\n��ҩʦ�ȵ����������ǵ�ָ��ͨ��С�Ľ����ˣ�\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("biyu xiao",me))
                carry_object("/clone/weapon/biyuxiao.c")->wield();
        else
                command("wield xiao");
        me->prepare_skill("finger");
        me->reset_action();
        me->prepare_skill("strike", "luoying-zhang");
        me->prepare_skill("leg", "xuanfeng-tui");
        me->set("combat_exp", 2000000);
        me->set("jiali", 100);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                return 1;
        }

        write("��ҩʦ˵�����ðɣ����һ�ؾ�������ˡ�\n");
        write("��ҩʦ˵������Ҫ��׼�����˾������ڶ��ذɣ�\n");
        tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�����ðɣ����һ�ؾ�������ˡ�\n", ({ob}));
        ob->set_temp("thd_marry", 2);
        return 1;
}

int ask_test2()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 2) {
                say("��ҩʦ�ȵ�����ô��������ô����\n");
                return 1; 
        }
        if (ob->query_temp("thd_marry") > 2) {
                command("say �Ѿ�������ػ�������ʲô��");
                return 1; 
        }
        
        command("say ��ν���������˹��̽����⣬����һ����ʲô��");
        return 1;
}

int ask_test3()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 3) {
                say("��ҩʦ�ȵ�����ô��������ô����\n");
                return 1; 
        }
        command("say �����澭�Ե�����֮����������������㣬�ǹ�....���������������ʲô��");
        return 1;
}

int ask_nvxu()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0;

        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id == ob->query("id")) {
                if (nvxu->query("death_count") < ob->query("death_count"))
                        command("say СŮ������Ȼ���ֹ��С�");
                else
                        say(CYN"��ҩʦЦ����" + RANK_D->query_rude(ob) + "�����������������\n"NOR);
        }
        else {
                if (id) {
                        if (!(user = find_player(id))) {
                                user = new(LOADUSER_OB, id);
                                user->set_name("", ({ id }));
                                if (!user->restore()) {
                                        command("say СŮ������Ȼ���ֹ��С�");
                                        destruct(user);
                                        return 1;
                                }
                                user_load = 1;
                        }
                }
                if (!id || nvxu->query("death_count") < user->query("death_count"))
                        command("say СŮ������Ȼ���ֹ��С�");
                else
                        command("say ���Ѱ�СŮ�����" + nvxu->query("name") + "Ϊ���ˡ�");
                if (user_load) destruct(user);
        }
        return 1;
}

