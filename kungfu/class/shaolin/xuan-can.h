#include <ansi.h>

void preparing(object, object);

string ask_me()
{
        mapping fam, my_fam, skl; 
        object fighter, me;
        string *sname;

        fighter = this_player();
        me = this_object();
        my_fam  = me->query("family");

        skl = fighter->query_skills();
        sname = keys(skl);
        if( fighter->query("combat_exp") > 2000000)
                return RANK_D->query_respect(fighter)+"�ľ����Ѿ���ǳ��������������������ս�ԵĹ����ɡ�\n";

        if(fighter->query_condition("lh_job"))
                return "��ղŲ����Ѿ��ʹ�����";

        if(fighter->query_condition("job_busy"))
                return "������æ�������������ء�";

        if(fighter->query("job_name") == "ѵ����ɮ")
                return "���ѵ����ɮ��������������Ϣһ��ɡ�";
                
        if( !fighter->query("luohan_winner") )
                return RANK_D->query_respect(fighter)+"���޺�����û����Ҳ�����ֵ�ڣ�";

        if(sizeof(skl)<15)
                return RANK_D->query_respect(fighter)+"���ֹ���ûѧ������Ҳ����ֵ��?";      

        if(fighter->query("family/generation") > 36)
                return RANK_D->query_respect(fighter)+"����̫�ͣ�ֻ���޺��õ��Ӳ�����Ĺ̡ܽ�\n";

        if ( mapp(fam = fighter->query("family")) && fam["family_name"] != "������")
                return RANK_D->query_respect(fighter)+"����Ц�ɣ��������ݵ������ɸ��֣�";

        if ( (int)fighter->query("guilty") > 0 )
                return RANK_D->query_respect(fighter)+"���۷����䣬�������������׼�������޺���Ч��?��";

        if( fighter->query_condition("job_busy"))
                return "��������æ�������������أ�";

        say("\n����˵�����ðɣ�������޺�����ѵ����ɮ�ɣ�����������֣����Ǹ����Ż������Ρ�\n");

//      fighter->set("short","�޺���ֵ�ڽ�ϰ");
        fighter->set_temp("lh_teacher",1);
        fighter->add("job_time/����",1);
        fighter->add("job_time/�޺���",1);
        fighter->delete_temp("meetmotou");
        fighter->set("job_name","ѵ����ɮ");
        fighter->apply_condition("lh_job", 15);
        fighter->apply_condition("job_busy",9);
                return "������ɮ�ã�ask monk about �似��";
}
