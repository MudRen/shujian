int valid_public(object me)
{
      mapping skl = me->query_skills();
      string *sk;
      int i;
      string skl_name = explode(__FILE__, "/")[<1][0..<3];

      if (!mapp(skl)) return 1;
      sk = keys(skl);
      i = sizeof(sk);
      while (i--) {
        if (sk[i] == "jiuyang-shengong" || sk[i] == "jiuyin-zhengong" || sk[i] == "lengquan-shengong" || sk[i] == "shenzhao-jing"
        || sk[i] == "hamagong" || sk[i] == "kuihua-shengong"|| sk[i] == "taixuan-gong" || sk[i] == "xixing-dafa" || sk[i] == "beiming-shengong"
        || sk[i] == "bahuang-gong" || sk[i] == "xiaowu-xianggong" || sk[i] == "xiantian-gong" || sk[i] == "tianmo-gong" || sk[i] == "taiji-shengong"
        || sk[i] == "yunu-xinjing"|| sk[i] == "huashan-qigong"|| sk[i] == "zixia-gong"|| sk[i] == "yinyun-ziqi"|| sk[i] == "bihai-chaosheng"
        || sk[i] == "hanbing-zhenqi"|| sk[i] == "longxiang-boruo"|| sk[i] == "huntian-qigong"|| sk[i] == "xuantian-wuji"|| sk[i] == "guiyuan-tunafa"
        || sk[i] == "yijin-jing"|| sk[i] == "qiantian-yiyang"|| sk[i] == "kurong-changong"|| sk[i] == "linji-zhuang"|| sk[i] == "huagong-dafa"
        || sk[i] == "shenyuan-gong"|| sk[i] == "shenghuo-shengong") continue;
        
        if (sk[i] != skl_name && SKILL_D(sk[i])->valid_enable("force"))
          return notify_fail("你不散掉"+to_chinese(sk[i])+"，如何能修习"+to_chinese(skl_name)+"。\n");
      }
      return 1;
}
