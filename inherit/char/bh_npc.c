// Modified by lonely@yxcs
#include <ansi.h>
inherit NPC;
mapping sites = ([
	"baituo"  :      "ŷ������",
	"emei"    :      "������",
	"wudu"    :      "�嶾��",
	"yihua"   :      "�ƻ���",
	"lingjiu" :      "���չ�",
	"xuedao"  :      "Ѫ����",
	"xueshan" :      "ѩɽ��",
	"mingjiao":      "��  ��",
	"wudang"  :      "��  ��",
	"xingxiu" :      "������",
	"honghua" :      "�컨��",
	"hu"      :      "�������",		
	"city2"   :      "��ػ�",
	"murong"  :      "Ľ������",
	"city"    :      "ؤ  ��",
	"taohua"  :      "�һ���",
	"huashan" :      "��ɽ��",
	"kunlun"  :      "������",
	"shenlong":      "������",
	"shaolin"  :     "������",
	"xiangyang":     "������",
	"xiaoyao" :      "��ң��",
	"quanzhen":      "ȫ����",
	"lingxiao":      "������",
]);

void setup() 
{

        set("zhengzhao",1 + random(3));
        ::setup(); 
        call_out("init_npc", 0, this_object()); 
} 

void init_npc(object ob)
{
        string area_file;
        object area;

        if (! objectp(ob) || ! environment(ob)) return;
        set("max_zhongcheng", 90 + random(10)); 
        set("zhongcheng", 11 + random(21));

        area_file = domain_file(base_name(environment(ob)));
        if( stringp(area_file) && member_array(area_file,keys(sites))!=-1 )
        {
            ob->set("area",sites[area_file]);
            ob->set("area_file",base_name(environment(ob)));
            area=new("/clone/misc/area1");
            area->create(sites[area_file]);
            if( area->query("banghui") )
            {    
                set("no_clean_up",1);
                set("banghui",area->query("banghui"));
                set("zhongcheng",area->query("zhongcheng"));
            }
            set("kaifa",area->query("kaifa"));
            set("jizhi",area->query("jizhi"));
            destruct(area);            
        }
        return;
}

int do_jiaru(object target);
// this function is used to improve NPC's zhongcheng
// and to hire these NPC
int accept_object(object target,object obj)
{
        mapping data;
        string *who;
        string stuffid,stuffname;
        if(! query("zhengzhao"))        return 0;
        if(! target->query("banghui"))  {
                command("say ��Ȼ"+RANK_D->query_respect(target)
                +"��˿��������Ҿ������ˡ�\n");
                return 1;
        }
        if( target->query("banghui")==(string)this_object()->query("banghui")) {
                command("say ���ǰ����ֵܣ��α���˿�����\n");
                return 0;
        }
        if(query("zhengzhao")==1)       {
                command("say "+RANK_D->query_self(this_object())
                +"ֻ���书����Ȥ������һ����̸��\n");
                return 0;
        }
    else
        if(query("zhengzhao")==2)       {
                if(query_temp("lonely/target")!=target) {
                        command("say �޹�����»����֪"+RANK_D->query_respect(target)+"����"+obj->query("name")+"�к����⣿\n");

                        return 0;

                }
                if(!obj->query("money_id"))     {
                        command("say "+RANK_D->query_self_rude(this_object())
                        +"ֻ��Ǯ����Ȥ������������Լ����Űɡ�\n");
                        return 0;
                }
                if(obj->value()<query_temp("money")*10) {
                        command("say �Ҳ���˵������"+
                        chinese_number(query_temp("money")/1000)
                        +"���ƽ���һ����Ҳ���У�\n");
                        return 0;
                }
                if(query("banghui")&&query("zhongcheng")>target->query_per())   {
                        command("say �����������Ǯ������ζԵ�������������֣�\n");
                        return 0;
                }
                return do_jiaru(target);
        }
    else
        if(query("zhengzhao")==3)       {
                data=query_temp("lonely/target");
                if(! mapp(data))        data=([]);
                who=keys(data);
                if(member_array(target->query("id"),who)==-1)        {
                        command("say �����ز���ʶ��Ϊ�θ�"+
                        RANK_D->query_self(this_object())+obj->query("name")+
                        "��\n");
                        return 0;
                }
                sscanf(data[target->query("id")],"%s:%s",stuffid,stuffname);
                if(stuffname != obj->query("name") ||
                        stuffid != obj->query("id"))    {
                        command("say "+RANK_D->query_respect(target)+
                        "������Ҫ����"+stuffname+"("+
                        stuffid+")������"+obj->query("name")+
                        "("+obj->query("id")+")��\n");
                        return 0;
                }
                if(query("banghui")&&query("zhongcheng")>target->query_per())   {
                        command("say ����������Ķ���������ζԵ�������������֣�\n");
                        return 0;
                }
                return do_jiaru(target);
        }
}



int do_jiaru(object target)
{
        object lp_me,lp_target;
        object area;
        string bh_me,bh_target;
        mapping data;
        if(! (bh_target=target->query("banghui")))      {
                command("say �ף���û�м����ᣬ������μ����أ�\n");
                return 0;
        }
        if( bh_target==query("banghui"))        {
                command("say ���Ƕ���ͬ����֣����º������\n");
                return 0;
        }
        if( sizeof(children(base_name(this_object())+".c")) > 2 || base_name(environment(this_object())) != query("area_file") ) {
                command("say "+RANK_D->query_self_rude(this_object())+
                "���岻�ʣ������´���˵�ɡ�\n");
                return 0;
        }
        lp_target=new("/clone/misc/lingpai");
        lp_target->create(bh_target);
        if(lp_target->query("no_use"))  {
                destruct(lp_target);
                command("say ��İ���ļ������⣬������ʦ��ϵ�ɡ�\n");
                return 0;
        }
        data=lp_target->query("npc");
        if(! mapp(data))        data=([]);
        data+=([query("id"):query("name")]);
        lp_target->set("npc",data);
//        lp_target->save();
       if(!undefinedp(target->query("lonely_quest"))
        && target->query("lonely_quest/type")==4)       {
        target->set("lonely_quest/over",1);
        target->add("bunch/quest",1);
        tell_object(target,"��������Ѿ���ɣ����ȥ����ɡ�\n");
        }
       if( query("area") && query("area_file") )
        {
            data=lp_target->query("area");
            if(!mapp(data)) data=([]);
            data += ([query("area"):query("area_file")]);
            lp_target->set("area",data);

           area=new("/clone/misc/area1");
            area->create(query("area"));
            area->set("banghui",bh_target);
            area->set("npc",this_object()->query("id"));
            area->set("npc_room",base_name(environment(this_object())));
            if( query("kaifa") && query("jizhi") )
            {
                area->set("kaifa",query("kaifa") );
                area->set("jizhi",query("jizhi") );
            }
            area->save();
            destruct(area);
        }
        lp_target->save();
        destruct(lp_target);
        if((bh_me=query("banghui")))    {
                lp_me=new("/clone/misc/lingpai");
                lp_me->create(bh_me);
                if(! lp_me->query("no_use"))    {
              if( query("area") && query("area_file") )
              {
                  data=lp_me->query("area");
                  if(! mapp(data)) data=([]);
                  map_delete(data,query("area"));
                  lp_me->set("area",data);
                  data=lp_me->query("npc");
                  if(! mapp(data)) data=([]);
                  map_delete(data,query("id"));
                  lp_me->set("npc",data); 

                  lp_me->save();
                  destruct(lp_me);
              }
             }
        }
        set("banghui",bh_target);
        add("zhongcheng",(query("max_zhongcheng")-query("zhongcheng"))*10/100);
        set("no_clean_up",1);
        if( query_temp("lonely/target"))
               delete_temp("lonely/target");
        command("say ��Ȼ"+RANK_D->query_respect(target)+
                "��˿�����"+RANK_D->query_self(this_object())+
                "������Ҳ���ܶԲ����㰡��\n");
        message_vision("$N���������ᡸ"+target->query("banghui")+"����\n",
                this_object());
        message("channel:rumor",YEL"��ҥ������ĳ�ˣ�"+query("name")+
        "�����ᡸ"+bh_target+"����\n"NOR,users());
        if( query("area") && query("area_file"))
        message("channel:rumor",YEL"��ҥ������ĳ�ˣ�"+query("area")+
        "����ᡸ"+bh_target+"���̲���\n"NOR,users());

        return 1;
}

void die()
{
        int kaifa;
        int kf;
        string banghui;
        object area;

        if(base_name(environment(this_object())) != query("area_file"))
        return ::die();

        if(! stringp(banghui=query("banghui")))
        return ::die();

        area=new("/clone/misc/area1");
        area->create(query("area"));
        if(area->query("no_use"))
        {
                destruct(area);
                return ::die();
        }

        kaifa=area->query("kaifa");
        kf=query("kaifa");
        if( kf==kaifa)
        {
                destruct(area);
                return ::die();
        }

        kaifa=kaifa-(random(10)+1);
        if(kaifa<=kf) kaifa=kf;

        area->set("kaifa",kaifa);
        area->save();
        destruct(area);

        message("channel:rumor",
                YEL"��ҥ������ĳ�ˣ�����"+query("name")+
                "��ɱ��"+query("area")+"�Ŀ����Ƚ�Ϊ"+kaifa
                +"��\n"NOR,users());
        return ::die();
}
