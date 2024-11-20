
/** @type { import("drizzle-kit").Config } */

export default {
  dialect: "postgresql",
  schema: "./utils/schema.js",

  dbCredentials: {
    url: 'postgresql://neondb_owner:ip3NvcmrUS6g@ep-spring-brook-a5mbtljn.us-east-2.aws.neon.tech/neondb?sslmode=require'
  }
};
