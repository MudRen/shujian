int ask_shenjian()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "�һ���") {
                command("say �����������������");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 2) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query("age") < 14) {
                command("say Ҫʹ�������ľ�����Ҫ�������㻹�ǵȳ���Щ��˵�ɡ�");
                return 1;
        }
/*
        if (ob->query("gender") == "����" && ob->query("age") < 40) {
                command("say ���б�����Ҳ���Խ������㣬������Ͳ������������õ�;����");
                return 1;
        }
*/
        if (ob->query_skill("luoying-zhang",1) < 80) {
                command("say Ҫʹ�������ľ�����Ҫ�����������㻹�Ƕ���ϰ��ϰ����Ӣ���ơ���˵�ɡ�");
                return 1;
        }
        write("��ҩʦ˵�������Ȼ���һ����ĵ��ӣ��Ҿͽ���һ�С��һ�Ӱ����񽣡��ɣ�\n");
        write("��ҩʦϸ�ĵ����㽲����һ�У�������ѧ���ˡ�\n");
        perform |= 2;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_yuxiao()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "�һ���") {
                command("say �����������������");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 1) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query("age") < 14) {
                command("say Ҫʹ�������ľ�����Ҫ�������㻹�ǵȳ���Щ��˵�ɡ�");
                return 1;
        }
/*
        if (ob->query("gender") == "����" && ob->query("age") < 40) {
                command("say ���б�����Ҳ���Խ������㣬������Ͳ������������õ�;����");
                return 1;
        }
*/
        if (ob->query_skill("yuxiao-jian",1) < 80) {
                command("say Ҫʹ�������ľ�����Ҫ����Ľ������㻹�Ƕ���ϰ��ϰ�����｣������˵�ɡ�");
                return 1;
        }
        write("��ҩʦ˵�������Ȼ���һ����ĵ��ӣ��Ҿͽ���һ�С��̺�����������ɣ�\n");
        write("��ҩʦϸ�ĵ����㽲����һ�У�������ѧ���ˡ�\n");
        perform |= 1;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_kuangfeng()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "�һ���") {
                command("say " +  RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 4) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query("age") < 14) {
                command("say Ҫʹ�������ľ�����Ҫ�������㻹�ǵȳ���Щ��˵�ɡ�");
                return 1;
        }
/*
        if (ob->query("gender") == "����" && ob->query("age") < 40) {
                command("say ���б�����Ҳ���Խ������㣬������Ͳ������������õ�;����");
                return 1;
        }
*/
        if (ob->query_skill("luoying-zhang",1) < 100 && ob->query_skill("xuanfeng-tui",1) < 100) {
                command("say Ҫʹ�������ľ�����Ҫ������Ʒ����ȷ����㻹�Ƕ���ϰ��ϰ����Ӣ���ơ��͡�����ɨҶ�ȡ���˵�ɡ�");
                return 1;
        }
        write("��ҩʦ˵�������Ȼ���һ����ĵ��ӣ��Ҿͽ���һ���ҵĿ��ҹ��򡰿��������ɣ�\n");
        write("��ҩʦϸ�ĵ����㽲����һ�У�������ѧ���ˡ�\n");
        perform |= 4;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_lingxi()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "�һ���") {
                command("say " +  RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 8) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query("age") < 14) {
                command("say Ҫʹ�������ľ�����Ҫ�������㻹�ǵȳ���Щ��˵�ɡ�");
                return 1;
        }
/*
        if (ob->query("gender") == "����" && ob->query("age") < 40) {
                command("say ���б�����Ҳ���Խ������㣬������Ͳ������������õ�;����");
                return 1;
        }
*/
        if (ob->query_skill("tanzhi-shentong",1) < 100) {
                command("say Ҫʹ�������ľ�����Ҫ��ǿ��ָ�����㻹�Ƕ���ϰ��ϰ����ָ��ͨ����˵�ɡ�");
                return 1;
        }
        write("��ҩʦ˵�������Ȼ���һ����ĵ��ӣ��Ҿͽ��㡰��ָ��ͨ���ľ��С���Ϭһָ���ɣ�\n");
        write("��ҩʦϸ�ĵ����㽲����һ�У�������ѧ���ˡ�\n");
        perform |= 8;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_huayu()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "�һ���") {
                command("say " +  RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 16) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query("age") < 14) {
                command("say Ҫʹ�������ľ�����Ҫ�������㻹�ǵȳ���Щ��˵�ɡ�");
                return 1;
        }
/*
        if (ob->query("gender") == "����" && ob->query("age") < 40) {
                command("say ���б�����Ҳ���Խ������㣬������Ͳ������������õ�;����");
                return 1;
        }
*/
        if (ob->query_skill("tanzhi-shentong",1) < 120) {
                command("say Ҫʹ�������ľ�����Ҫ��ǿ��ָ�����㻹�Ƕ���ϰ��ϰ����ָ��ͨ����˵�ɡ�");
                return 1;
        }
        write("��ҩʦ˵�������Ȼ���һ����ĵ��ӣ��Ҿͽ��㡰��ָ��ͨ���ľ��С����컨�ꡱ�ɣ�\n");
        write("��ҩʦϸ�ĵ����㽲����һ�У�������ѧ���ˡ�\n");
        perform |= 16;
        ob->set("thd/perform", perform);
        return 1;
}
