//�Ͻ�ʹ�á�����ɱͷ�� By jpei@wl 2011

#include <ansi.h>

string *valid_type = ({
"force", "parry",  "dodge", "unarmed","claw",
"cuff",  "finger", "strike","hand",   "leg",
"sword", "blade",  "dagger","brush",  "spear",
"hook",  "stick",  "staff", "club",   "throwing",
"whip",  "axe",    "hammer","bow",
});

int sort_skill2(string sk) 
{
	return (SKILL_D(sk)->type() == "knowledge" && SKILL_D(sk)->type2() == "worker");
}

int sort_skill(string sk)
{
	return (SKILL_D(sk)->type() != "martial" && SKILL_D(sk)->type() != "array");
}

int sort_basic(string sk)
{
	return member_array(sk, valid_type)!=-1;
}

int main(object me,string arg)
{

 	
  object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, *allskills, str = "";
	int i, j;


    if (!arg)
            return notify_fail("�����ʲô��\n");

    if(!objectp(ob = present(arg, environment(me))))
            return notify_fail("����û������ˡ�\n");
    
    if(userp(me))
    	       return notify_fail("ʲô��\n");

 skl = ob->query_skills();

 allskills  = sort_array( keys(skl), (: strcmp :) );


	sname=filter_array( allskills, (: sort_skill2 :) );

	allskills-=sname;

	sname=filter_array( allskills, (: sort_skill :) );
	allskills-=sname;

//�����ǻ���

	sname=filter_array( allskills, (: sort_basic :) );
	allskills-=sname;


	j = sizeof(sname);

         if(j>0)   for(i=0; i<j; i++) {
                             ob->set_skill(sname[i], ob->query("max_pot",1)-100);
                  }


//����������
	sname=allskills;

	j = sizeof(sname);
         if(j>0)   for(i=0; i<j; i++) {
                             
                             if(sname[i]!="liumai-shenjian" )
                                 if(sname[i]!="pixie-jian" )
                                    if(sname[i]!="jiuyin-zhengong") 
                                       if(sname[i]!="jiuyin-shenfa")
                                          if(sname[i]!="shenzhao-jing")
                                            if(sname[i]!="wuxing-zhen")
                                              if(sname[i]!="wuhu-duanmendao")
                                                if(sname[i]!="qianzhu-wandushou")
                                                  if(sname[i]!="lengquan-shengong")
//                                             if(sname[i]!="wuhu-duanmendao")
//                                           if(sname[i]!="wuhu-duanmendao")
//                                         if(sname[i]!="wuhu-duanmendao")
//                                       if(sname[i]!="wuhu-duanmendao")
//                                     if(sname[i]!="wuhu-duanmendao")
//                                   if(sname[i]!="wuhu-duanmendao")
//                                 if(sname[i]!="wuhu-duanmendao")
//                               if(sname[i]!="wuhu-duanmendao")
//                             if(sname[i]!="wuhu-duanmendao")
//                           if(sname[i]!="wuhu-duanmendao")

                                                                          ob->set_skill(sname[i], ob->query("max_pot",1)-100);
                  }
// CHANNEL_D->do_channel(this_object(), "rumor", HIC"��˵" + ob->name(1) + "�ӻ���ҵ���ʦ��ѧ�������еļ��ܣ�\n"NOR);

	return 1;

}

